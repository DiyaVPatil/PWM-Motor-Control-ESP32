# Firmware

The ESP32 firmware provides wireless, browser-based control of two DC motors using PWM.

## Software Used

- **C++** — ESP32 firmware using the Arduino framework, uses the WiFi.h library to create a Wi-Fi access point hosted by the ESP32 and 
            WebServer.h to handles HTTP requests from the control dashboard.
- **HTML/CSS** — Builds and styles the web interface
- **JavaScript** — Sends motor control commands to the ESP32
- **LEDC PWM** — Generates 5 kHz, 8-bit PWM signals for motor speed control

## Functionality

The ESP32 hosts a local web dashboard where users can independently:

- Adjust Motor A and Motor B speed from 0–100%
- Start and stop each motor
- Control the motors wirelessly through a web browser

The dashboard communicates with the ESP32 through HTTP requests, which the firmware converts into PWM outputs for the motor control circuitry.
