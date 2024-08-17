# MFPV-PiFli 
## WiFi enabled Access Point for the MFPV Platform

### If you haven't, [check out MFPV beforehand](https://github.com/mikeymascatu/MFPV)

## Description

This WIP module is intended for a replacement for the MFPV-RX2 Secondary reciever. This new module provides enhanced connectivity to MFPV modules. This makes it simple to connect to the MFPV drone's secendary hardware with only a mobile device. This is based on the Raspberry Pi Pico WH (W also works but soldering headers is required)

### Notes:
DO NOT USE THIS Module for longer-range missions. This module is intended for short range operation.

## Printing:

The case for the module can be found [here](https://www.printables.com/model/653851-press-fit-raspberry-pi-pico-wh-case-fully-protects/files)

The MFPV-XLconnector can be used to secure the PiFli module. Click the 2 connectors to each other and slide the case between the 2 parts.

## Installation:

* Install Ardunio IDE 2.0 or newer
* Add the Pi Pico W(H) in Additional Board Manager URLs:

```
https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json

```

* Install the following Ardunio Libaries 
  - WiFi: setups up WiFi AP

* Download the V0.1.ino file from the repo.

* Open it in Ardunio IDE

* Plug in the module and select "Raspberry Pi Pico W" in the proper serial port
       - If installing this for the first time especially after other firmware, hold BOOTSEL on the rear of the clock before plugging in

* Edit the SSID and PASS near the top to match your desired WiFi credientals 

* Select Verify, wait for the compilation to complete 

* Select Upload, wait for the Pi to finish flashing

* On your computer, you should be able to see your wifi SSID show up. The NetController access IP is 192.168.42.1


