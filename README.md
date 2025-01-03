# Automatic-Toll-Gate-Control
This project demonstrates an automatic toll gate control system using a servo motor and an ultrasonic sensor. The system detects the presence of a vehicle using the ultrasonic sensor and operates the servo motor to open or close the toll gate accordingly. The implementation is designed for the ATmega328P microcontroller and is developed using [PlatformIO](https://platformio.org/).

## Features

- **Vehicle Detection**: Uses an ultrasonic sensor (HC-SR04) to detect vehicles approaching the toll gate.
- **Gate Control**: Controls a servo motor to open and close the gate based on vehicle proximity.
- **AVR Microcontroller**: Built for the ATmega328P, leveraging low-level hardware control for precise operations.

## Requirements

### Hardware
- ATmega328P Microcontroller (e.g., Arduino Uno)
- HC-SR04 Ultrasonic Sensor
- Servo Motor (e.g., SG90 or MG995)
- Breadboard and jumper wires

### Software
- PlatformIO Core (Install via [VS Code](https://platformio.org/install/ide?install=vscode))
- AVR Toolchain (pre-installed with PlatformIO)

## Circuit Diagram

1. **Servo Motor Connections**:
   - Signal pin to `PB1` (OC1A, Pin 9 on Arduino Uno).
   - Connect power and ground as per the servo motor's requirements.

2. **Ultrasonic Sensor Connections**:
   - Trigger pin to `PD5` (Pin 5 on Arduino Uno).
   - Echo pin to `PD6` (Pin 6 on Arduino Uno).

3. **Power**:
   - Provide the correct power supply to the ATmega328P and connected peripherals.
