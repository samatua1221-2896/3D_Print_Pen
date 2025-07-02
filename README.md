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

## Assembly Instructions

Most of this is a pretty straightforward setup with the PCB board being the main center of the pen that has all of the THT components sticking out of the case in order or operation to happen. If it is not defined inside of the 3D model how something is secured, the object is glued to the nearest surrounding case area. For example, the hotend nozzle will be glued to the innermost cylinder in order to minimize the amount of screws and scructural instability inside of the case itself.

## Bill Of Materials

|                     Item               |  Quantity |      Price    |                                      Link                                    |
|----------------------------------------|-----------|---------------|-----------------------------------------------------------------------|
|      Arduino Nano                      |     3     |     $7.99     |    https://www.amazon.com/YELUFT-ATmega328P-Microcontroller-Mini-USB/dp/B0DWMQVCRF/ref=sr_1_9?crid=3N1J84LJP6D8T&dib=eyJ2IjoiMSJ9.l25zh--muurGeoTSJmeooOXaF8A63oJ3_c-9fVVcHog5BGa4Lu2sPUkQxNLwgIW9jzwkfb0FuKb-xdIJ7CoDm4nfWcg_hOse8iSX0BVdCoWrOft-FsZH_LRwnKvv2QNP8DzT_T0FBm2K6c1-ryUEguuDBPjfuYehwj9scuuCvK3hnk_tx6lNvgV1F00UnO9U56-RpO-24WSspVKbrjiBYbu_g6KfBlel1uN68UF1GBK7dsJkTn6oMsSCKJ0GVjl3qGr4at7lzIT2sfEbrdl445vNXnM15akMi2Rq827A9Gc.wGK8uIL5xv32oeMyIoTqSfKMEPixhKiYXT65sDOd9bU&dib_tag=se&keywords=Arduino%2BNano%2BV3.0%2Bwith%2Bheaders&qid=1750405718&s=industrial&sprefix=arduino%2Bnano%2Bv3.0%2Bwith%2Bheaders%2Cindustrial%2C245&sr=1-9&th=1     |
|     IRLZ44N MOSFET                     |     1     |     $1.30     |     https://www.digikey.com/en/products/detail/infineon-technologies/IRLZ44NPBF/811808    |
|     L293D Motor Driver IC              |     1     |     $7.85     |     https://www.digikey.com/en/products/detail/stmicroelectronics/L293D/634700    |
|     10K Potentiometer (Vertical Mount) |     1     |     $0.78     |    https://www.digikey.com/en/products/detail/amphenol-piher-sensing-systems/PT10WV10-103A2020-3-NE-S/13244529?gad_source=1&gad_campaignid=20243136172&gbraid=0AAAAADrbLljQ6ae9GtqJU8Qi6yQqZdeEQ&gclid=Cj0KCQjwjdTCBhCLARIsAEu8bpKEUfNeJhMs6WRIgIcLK17HQyBX3QXcHx0sI51iWuGOn8gcYR4reZ4aAh5HEALw_wcB&gclsrc=aw.ds     |
|     MK8 Hotend Heating Kit             |     1     |     $17.35    |    https://www.amazon.com/KITQLPG-Assembled-Extruder-Aluminum-Creality/dp/B0DM1XC4MV/ref=sr_1_7?crid=1GE63CO4X2I03&dib=eyJ2IjoiMSJ9.1sTw7q0blSYTkI2YdtyXIF6r6eS1UPCfpMMrMzdQ3O2vPv8Q2_ke6nCaoIZurI6kA4nVzLIayCC3nMHq97cGw87BuRVNYd5dtnQfQIYzN2dyn5O7bk-8xmRiPRiBSt_OQbNnVPVvXxPNRM5mBcpmVl9Z0rYFVjX7363TjlFGGUGgphZ1rK8WO17pZ28ssokofxpMSGD0rIxDQLPzGGy-l6u-Ao9eU0aV5-fw6NNLC__okYzfG0cr7Xzs_SkJWiLKnIHSE3mUL_0vAQ0s4FUm0MpId8ATXTyihLFomqIwhP4.FgA4OCpQMqMa4RdHlC55trs-xEOYAF8lMCT4hApZ1A8&dib_tag=se&keywords=MK8%2BHotend%2BHeating%2BKit%2B12V&qid=1750499927&s=industrial&sprefix=mk8%2Bhotend%2Bheating%2Bkit%2B12v%2Cindustrial%2C401&sr=1-7&th=1     |
|     12V 2A Power Adapter               |     1     |     $0.00     |    N/A     |
|    220 Ohm Resistor                    |     1     |     $0.10     |    https://www.digikey.com/en/products/detail/vishay-beyschlag-draloric-bc-components/MBA02040C2203FRP00/336479     |
|    10K Ohm Resistor                    |     2     |     $0.20     |     https://www.digikey.com/en/products/detail/stackpole-electronics-inc/RNF14FTD1K00/1706678    |
|    100uF 16V Electrolytic Capacitor    |     2     |     $0.24     |     https://www.digikey.com/en/products/detail/w%C3%BCrth-elektronik/860020372006/5727030    |
|    0.1uF Ceramic Capacitor             |     2     |     $0.44     |     https://www.digikey.com/en/products/detail/kemet/C320C104K5R5TA/818040    |
|    100K NTC Thermsistor EPCOS          |     1     |     $0.82     |     https://www.digikey.com/en/products/detail/epcos-tdk-electronics/B57891M0104J000/739908?s=N4IgTCBcDaIKIAUDCB5AygAgEIFYDsAHAJwCMAsgAwkUAsAUhYyALoC%2BQA    |
|    Mini DC Motor 12 V                  |     1     |     $7.31     |     https://www.amazon.com/Motor-DC12V-11RPM-Right-Printing/dp/B0B82JPGRB/ref=sr_1_3?crid=3CB6OWH0B720C&dib=eyJ2IjoiMSJ9.D41ml4U9xLVtxhbHP27dEpFo9spnGY6fKuCrxLomp4hUtC9cHtbbuF9wp16bQ9WnRDYRtU1hqldkQYHr_Wcw9KJl4UdeJkqRMRdCRFVTfie2kPKt-qtSHMfiOjHyGYh-Uj-jPV2O2cZ6S4Qu13PIBx0lCTZCxret9eCrOeZTDPn4S6KgdygBDNwYvTDtYFRCwuYBj8hSs5le9dJBReeIonGyX0iht3gTK1B1HFETX0C7Sny7-PXHt0FG_HkXJh8ZiNqnsGz5hPMfTozDW7nt-FVIzVdoMNSK3uEo0LOIEaQ.Lf3NHbVL75z6TmyG8ovsjnzQNKod5lcOAI5Ky-7hfzE&dib_tag=se&keywords=Micro+Right+Angle+Gear+Motor&qid=1750409181&s=industrial&sprefix=micro+right+angle+gear+motor%2Cindustrial%2C296&sr=1-3    |
|    Terminal Block 2-pin 3.5mm          |     2     |     $0.72     |     https://www.digikey.com/en/products/detail/w%C3%BCrth-elektronik/691137710002/6644051    |
|    Pin Header 1x2 2.54                 |     1     |     $0.10     |     https://www.digikey.com/en/products/detail/harwin-inc/M20-9990246/3728226    |
|    M3 Screws                           |     12    |     $5.89     |     https://www.digikey.com/en/products/detail/apm-hexseal/RM3X10MM-2701/3712296    |
|    18 AWG Wire                         |      1    |     $6.99     |    https://www.amazon.com/Automotive-Flexible-Security-Stranded-Electrical/dp/B0CKR35SX5/ref=sr_1_19?crid=1F4GFUSG8KNF6&dib=eyJ2IjoiMSJ9.uHK5UXp4hf0bwt6AfnruppJM3pUA32v8GcUwu4udGvcSCvaws5msk8wJm_Jr3ouFghZm0KNip0AoXKJtf2pnJTNHGqKtM6UcdhImrNy6rK7MXCeostqYGApJps1KpCjMrt_RAFSUFeeNNCqbJsm2DBd8UH-DOCgMq-9XmZye_IWQjNhCKf92AGalKAKIZxk_TFK6w9WRP426VKyM_MKrWEWLFlgYr2gQvP2ya433jWM7ujgjP4iFdJtdX_-3S_k6DZ2Jx-fXkmWO9Vb4T-ASV-hyWtiTQHDfQ9qiCEIqkGo._wcq8Oockpcvah8JYsrHZlqZNoG3ZC45Jwo8J2QU664&dib_tag=se&keywords=18%2Bawg%2Bwire&qid=1750415217&s=industrial&sprefix=18%2BAWG%2Cindustrial%2C273&sr=1-19&th=1     |
|    22 AWG Wire                         |      1    |     $8.98     |     https://www.amazon.com/Electrical-Gauge-Silicone-Cable-Black/dp/B0746HG158/ref=sr_1_17?crid=1TLAQ1FE1E9UJ&dib=eyJ2IjoiMSJ9.pyl_5iNHOLas3h4fTLyq3ptcaen0H19fqStwe3jN_-Lkk6ZuUwe1nSgojOlEf2Qw-tZbNN6sDRSJVMNIeeshOkHBHr5oW1QADB0kr4yS2xj47Znjt9_Xk2DYurntQ4ztnaI-7s2Zpy2jnwvsQdppBVu6ggUt9N33nzIovA1__chHq5FQ0Apt-Sdx-lpnnT0OuWI10XU7Sz4VhJTtx3sx0kmxd4cErrKY-_PYvIZzZCqRQ69wtD6B0ShksGWvWZM7s6Tqc-kdndNEhOmdhqEOTDRJ6lF_74H1YwXbmILCK0o.CKzEWAde0ZKLLJGwiscanEUdFUtN2LvgcJuKoCMr8hU&dib_tag=se&keywords=22%2Bawg%2Bwire&qid=1750415326&s=industrial&sprefix=22%2Bawg%2Bwire%2Cindustrial%2C193&sr=1-17&th=1    |
|    Buttons                             |      2    |     $2.74     |     https://www.digikey.com/en/products/detail/c-k/D6C90-F2-LFS/1466345    |
|    Shipping for DigiKey                |      1    |     $20.00    |     N/A    |
|    Shipping for Printing Legion        |      1    |     $10.00    |     N/A    |
|    DC Barrel Jack                      |      1    |     $1.50     |     https://www.digikey.com/en/products/detail/same-sky-formerly-cui-devices/PJ-202AH/408450    |
|    PCB Board                           |      1    |     $15.28    |    JLCPCB  |
|                                        |           |               |            |
|    Total Cost                          |           |     $119.32   |            |
