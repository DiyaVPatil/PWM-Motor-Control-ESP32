# ESP32 PWM Motor Controller
A custom PCB-based motor controller designed in KiCad for efficient PWM speed control of brushed DC motors using an ESP32 microcontroller.

This project began as a perfboard prototype and was later redesigned as a custom printed circuit board to improve physical dimensions and manufacturability.

## Features
- ESP32-based PWM motor control
- Adjustable motor speed (0–100% duty cycle)
- Logic-level MOSFET driver stage
- Flyback diode protection
- Battery-powered operation (3.7 V Li-ion)
- Compact custom PCB designed in KiCad

## Hardware
1) ESP32 DevKit | Main microcontroller 
2) IRLB8748 | Logic-level N-channel MOSFET 
3) Schottky Diode | Flyback protection 
4) TP4056 | Li-ion charging module 
5) 3.7 V Li-ion Battery | Portable power source 
6) Coreless DC Motor | Demonstration load 

## Project Timeline

### Version 1
Perfboard prototype built from KiCad schematic as a "proof-of-concept"

### Version 2
Final custom KiCad PCB, after making improvements from the perfboard prototype. 

## Future Improvements

- Real-time speed feedback on an OLED display
- Battery percentage monitoring
- Current sensing
- Bluetooth control
- Closed-loop speed control using encoder feedback

## Repository Structure
Note that there is a functionality video available under images and BOM
```
ESP32-PWM-Motor-Controller/

firmware/
hardware/
kicad/
images and BOM/
docs/
README.md
```

## Author

Diya

Electrical Engineering Student  
University of California, Riverside
