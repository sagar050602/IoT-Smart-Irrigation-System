# IoT-Smart-Irrigation-System
# IoT Smart Irrigation System (Proteus Simulation)

## Overview
This project implements an IoT-enabled smart irrigation system using an ESP8266 NodeMCU.
Soil moisture is monitored using an analog input, and a relay-controlled water pump is
automatically activated when the soil is dry.

The firmware is designed to support cloud monitoring and manual control using Blynk.
Functional validation of sensor logic and relay control is performed using Proteus simulation.

## Features
- ADC-based soil moisture sensing
- Automatic pump control using threshold logic
- Manual override via Blynk (designed)
- Non-blocking firmware using millis()
- Relay driver with transistor and flyback diode
- Proteus-based simulation and validation

## Tools & Technologies
- ESP8266 NodeMCU
- Embedded C / Arduino
- Proteus Design Suite
- Blynk IoT Platform (design-level)
- Relay driver (2N2222 + 1N4007)

## Note
Wi-Fi and cloud communication are part of the firmware design.
Due to simulation limitations, IoT connectivity is not executed in Proteus.
