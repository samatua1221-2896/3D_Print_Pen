# 3D_Print_Pen

This is a fully custom 3D print pen that is able to use standard 1.75 filament and work with temperatures of 130°C to 240°C

![fullModel](https://github.com/user-attachments/assets/4c9a7176-e4a8-4b15-970d-9f4cf7dd4ce6)

## Features

- Uses an Arduino Nano to control heating and motor functions
- Temperature dial lets you adjust the nozzle from 130 °C to 240 °C
- PID-controlled heater ensures smooth, stable temperature during use
- 12V 40W MK8-style heater cartridge melts standard 1.75 mm filament
- Compact custom PCB designed in KiCad
- Extrude button: hold to feed, double-tap for continuous release, tap again to stop
- Retract button: same controls in reverse for removing filament
- Motor direction and latching fully handled in firmware with debounce and timing
- Heater auto-shuts off if temp exceeds 260 °C or if thermistor fails
- Failsafe defaults ensure motor and heater are off on startup or error

## Details

This was pretty much my first full dive into a full blast of hardware and software combined in my own project that I'm making from scratch. I got inspiration from the MYNT3D style pen that I had but had been dealt some damage with wear and tear over the years so I decided to try and make my own. Overall, this was a pretty fun project where I was able to get a much better understand of KiCad and Onshape which is definitely going to help me for future projects that I'll be working on. A 3D print pen is also pretty close to a 3D printer that I'm hoping to get but if all else fails I'll have a pretty cool piece of hardware that I'll know I completely designed from scratch.

## Photos

Front & Back Exploded Views

![frontExplodedView](https://github.com/user-attachments/assets/d7c0c767-4941-4af7-9270-b47e93861a9f)
![backExplodedView](https://github.com/user-attachments/assets/87cf99ec-3a75-4c4b-83c9-641c254b4ca1)

Pictures of PCB Board Front & Back

![frontPrintPenPCB](https://github.com/user-attachments/assets/e48cfcb5-47f0-498b-8707-7ee6bc31fba4)
![backPrintPenPCB](https://github.com/user-attachments/assets/1207a3f9-5243-4380-a016-5daf8046a94b)

Schematic Wiring

![printPenSchematic](https://github.com/user-attachments/assets/828af017-3fdc-4684-8506-7fb776147e23)

## Bill Of Materials

|  Item   |  Quantity  |  Price  |  Link  |
|------------------------------------------|---------|------------|--------|
|      Arduino Nano    |    3      |     $7.99     |     https://www.amazon.com/YELUFT-ATmega328P-Microcontroller-Mini-USB/dp/B0DWMQVCRF/ref=sr_1_9?crid=3N1J84LJP6D8T&dib=eyJ2IjoiMSJ9.l25zh--muurGeoTSJmeooOXaF8A63oJ3_c-9fVVcHog5BGa4Lu2sPUkQxNLwgIW9jzwkfb0FuKb-xdIJ7CoDm4nfWcg_hOse8iSX0BVdCoWrOft-FsZH_LRwnKvv2QNP8DzT_T0FBm2K6c1-ryUEguuDBPjfuYehwj9scuuCvK3hnk_tx6lNvgV1F00UnO9U56-RpO-24WSspVKbrjiBYbu_g6KfBlel1uN68UF1GBK7dsJkTn6oMsSCKJ0GVjl3qGr4at7lzIT2sfEbrdl445vNXnM15akMi2Rq827A9Gc.wGK8uIL5xv32oeMyIoTqSfKMEPixhKiYXT65sDOd9bU&dib_tag=se&keywords=Arduino%2BNano%2BV3.0%2Bwith%2Bheaders&qid=1750405718&s=industrial&sprefix=arduino%2Bnano%2Bv3.0%2Bwith%2Bheaders%2Cindustrial%2C245&sr=1-9&th=1    |
|     IRLZ44N MOSFET                       |     1      |     $1.30     |         |
|     L293D Motor Driver IC                |     1      |     $7.85     |         |
|     10K Potentiometer (Vertical Mount)   |     1      |     $0.78     |         |
|     MK8 Hotend Heating Kit               |     1      |     $17.35     |         |
|     12V 2A Power Adapter                 |     1      |     $0.00     |         |
|     220 Ohm Resistor                     |     1      |     $0.10     |         |
|     10K Resistor                         |     2      |     $0.10     |         |
|     100uF 16V Electrolytic Capacitor     |     2      |     $0.20     |         |
|     0.1uF Ceramic Capacitor              |     2      |     $0.20     |         |
|     100K NTC Thermsistor EPCOS           |     1      |     $0.24     |         |
|     Mini DC Motor 12V                    |     1      |     $0.44     |         |
|     Terminal Block 2-pin 3.5 mm          |     2      |     $0.82     |         |
|     Pin Header 1x2 2.54                  |     1      |     $7.31     |         |
|     M3 Screws                            |     12     |     $0.72     |         |
|     18 AWG Wire                          |     1      |          |         |
|     22 AWG Wire                          |     1      |          |         |
|     Buttons                              |     2      |          |         |
|     Shipping for Digikey                 |     1      |          |         |
|    3D Parts (Printing Legion)            |     1      |          |         |
|     DC Barrel Jack                       |     1      |          |         |
|     PCB & Shipping                       |     1      |          |         |
