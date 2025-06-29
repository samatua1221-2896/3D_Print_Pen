/* -----------------------------------------------------------------
   DIY 3‑D Printing Pen – Full Firmware
   Hardware (per KiCad project):
     * Arduino Nano V3 / Nano Every
     * L293D (IN1 = D2, IN2 = D3, EN1/2 tied HIGH or PWM for speed)
     * IRLZ44N MOSFET gate on D9  (Heater PWM)
     * Extrude button  on D4   (to GND, INPUT_PULLUP)
     * Retract button  on D5   (to GND, INPUT_PULLUP)
     * Potentiometer   on A1   (10 kΩ, sets 130‑240 °C)
     * Thermistor      on A0   (100 kΩ NTC, β ~ 3950, 10 kΩ pull‑up to 5 V)
------------------------------------------------------------------- */

#include <Arduino.h>

/* ---------- PIN DEFINITIONS ---------- */
constexpr uint8_t PIN_IN1       = 2;    // L293D IN1 (Motor FWD)
constexpr uint8_t PIN_IN2       = 3;    // L293D IN2 (Motor REV)
constexpr uint8_t PIN_BTN_FWD   = 4;    // Extrude button
constexpr uint8_t PIN_BTN_REV   = 5;    // Retract button
constexpr uint8_t PIN_HEATER    = 9;    // MOSFET gate PWM
constexpr uint8_t PIN_THERMIST  = A0;   // Thermistor
constexpr uint8_t PIN_POT       = A1;   // Temp set potentiometer

/* ---------- CONSTANTS ---------- */
const float    BETA        = 3950.0;    // β constant of thermistor
const float    T0          = 298.15;    // 25 °C in Kelvin
const float    R0          = 100000.0;  // 100 kΩ at 25 °C
const float    PULLUP      = 10000.0;   // 10 kΩ pull‑up resistor
const uint16_t ADC_MAX     = 1023;
const float    VREF        = 5.0;       // ADC reference voltage

const uint16_t TEMP_MIN_C  = 130;       // lower limit of set‑pot range
const uint16_t TEMP_MAX_C  = 240;       // upper limit

/* PID tuning (start values, adjust by experiment) */
float Kp = 10.0;
float Ki = 0.6;
float Kd = 50.0;

/* Button timing  */
const unsigned long DEBOUNCE_MS = 25;
const unsigned long DOUBLE_MS   = 400;

/* Safety limits */
const uint16_t TEMP_MAX_SAFE = 260;   // °C, heater shutdown threshold

/* ---------- ENUMS & STRUCTS ---------- */
enum MotorState { STOPPED, FORWARD, REVERSE };

struct Btn {
  uint8_t  pin;
  bool     lastLevel;
  bool     isDown;
  unsigned long lastChange;
  unsigned long firstClick;
  bool     latched;
};

/* ---------- GLOBALS ---------- */
Btn btnFwd = {PIN_BTN_FWD, HIGH, false, 0, 0, false};
Btn btnRev = {PIN_BTN_REV, HIGH, false, 0, 0, false};

MotorState motorState = STOPPED;

float tempSetC  = 0;
float tempNowC  = 0;

/* PID terms */
float pidIntegral = 0;
float pidPrevErr  = 0;
unsigned long lastPIDms = 0;
const unsigned long PID_INTERVAL_MS = 200;

/* ---------- FUNCTION DECLARATIONS ---------- */
float readTemperatureC();
void  updatePID();
void  setHeaterPWM(uint8_t duty);
void  setMotor(MotorState st);
void  handleButton(Btn &b, MotorState dir);

/* -------------------- SETUP -------------------- */
void setup() {
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_HEATER, OUTPUT);

  pinMode(PIN_BTN_FWD, INPUT_PULLUP);
  pinMode(PIN_BTN_REV, INPUT_PULLUP);

  /* Safe defaults */
  setMotor(STOPPED);
  setHeaterPWM(0);

#ifdef SERIAL_PORT_USBVIRTUAL
  Serial.begin(115200);
#endif
}

/* -------------------- MAIN LOOP -------------------- */
void loop() {

  /* ----- BUTTON LOGIC FOR MOTOR ----- */
  handleButton(btnFwd, FORWARD);
  handleButton(btnRev, REVERSE);

  /* ----- TEMPERATURE SETPOINT ----- */
  int potRaw = analogRead(PIN_POT);
  tempSetC = map(potRaw, 0, ADC_MAX, TEMP_MIN_C, TEMP_MAX_C);

  /* ----- READ THERMISTOR ----- */
  tempNowC = readTemperatureC();

  /* ----- SAFETY SHUTDOWN ----- */
  if (tempNowC > TEMP_MAX_SAFE || tempNowC < 0) {
    // Sensor failure or runaway
    setHeaterPWM(0);
  } else {
    /* ----- PID HEATER CONTROL ----- */
    unsigned long now = millis();
    if (now - lastPIDms >= PID_INTERVAL_MS) {
      updatePID();
      lastPIDms = now;
    }
  }

#ifdef SERIAL_PORT_USBVIRTUAL
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 1000) {
    Serial.print("Set:"); Serial.print(tempSetC);
    Serial.print("  Now:"); Serial.print(tempNowC);
    Serial.print("  Motor:"); Serial.println(motorState);
    lastPrint = millis();
  }
#endif
}

/* ====================================================
   BUTTON HANDLER
==================================================== */
void handleButton(Btn &b, MotorState dir) {
  bool level = digitalRead(b.pin);
  unsigned long now = millis();

  /* Debounce */
  if (level != b.lastLevel) {
    b.lastChange = now;
    b.lastLevel  = level;
  }
  if (now - b.lastChange < DEBOUNCE_MS) return;

  /* On press (level LOW) */
  if (!level && !b.isDown) {
    b.isDown = true;
    if (now - b.firstClick < DOUBLE_MS) {          // Double click
      b.latched = !b.latched;                      // Toggle latch
      if (b.latched) setMotor(dir);
      else           setMotor(STOPPED);
      b.firstClick = 0;
    } else {
      b.firstClick = now;                          // Start click timer
    }
  }

  /* On release */
  if (level && b.isDown) {
    b.isDown = false;
    if (!b.latched && (now - b.firstClick >= DOUBLE_MS)) {
      setMotor(STOPPED);                           // End of momentary
    } else if (b.latched) {                        // Single click stops latched
      b.latched = false;
      setMotor(STOPPED);
    }
  }

  /* Momentary running while held */
  if (b.isDown && !b.latched) setMotor(dir);
}

/* ====================================================
   MOTOR CONTROL
==================================================== */
void setMotor(MotorState st) {
  motorState = st;
  switch (st) {
    case FORWARD:
      digitalWrite(PIN_IN1, HIGH);
      digitalWrite(PIN_IN2, LOW);
      break;
    case REVERSE:
      digitalWrite(PIN_IN1, LOW);
      digitalWrite(PIN_IN2, HIGH);
      break;
    case STOPPED:
    default:
      digitalWrite(PIN_IN1, LOW);
      digitalWrite(PIN_IN2, LOW);
  }
}

/* ====================================================
   HEATER PID
==================================================== */
void updatePID() {
  float err = tempSetC - tempNowC;
  pidIntegral += err * (PID_INTERVAL_MS / 1000.0);
  float derivative = (err - pidPrevErr) / (PID_INTERVAL_MS / 1000.0);
  float out = Kp * err + Ki * pidIntegral + Kd * derivative;

  /* Clamp and write PWM */
  out = constrain(out, 0, 255);
  setHeaterPWM((uint8_t)out);
  pidPrevErr = err;
}

void setHeaterPWM(uint8_t duty) {
  analogWrite(PIN_HEATER, duty);
}

/* ====================================================
   THERMISTOR CONVERSION
==================================================== */
float readTemperatureC() {
  int raw = analogRead(PIN_THERMIST);
  if (raw <= 0 || raw >= ADC_MAX) return -100.0;   // Detect open/short

  float v = (raw * VREF) / ADC_MAX;
  float rTherm = PULLUP * ( (VREF / v) - 1.0 );
  if (rTherm <= 0) return -100.0;
  float invT = 1.0/T0 + (1.0/BETA) * log(rTherm / R0);
  float tempK = 1.0 / invT;
  float tempC = tempK - 273.15;
  return tempC;
}
