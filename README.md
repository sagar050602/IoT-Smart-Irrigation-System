# IoT-Smart-Irrigation-System
ESP8266-based smart irrigation system with ADC soil moisture sensing and relay-controlled pump, validated using Proteus simulation and designed for IoT cloud integration.

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

## Firmware Notes
- Written for ESP8266 NodeMCU
- Uses ADC (A0) for soil moisture sensing
- Relay controlled via GPIO D1
- Designed for Blynk cloud integration
- Tested logic flow using Proteus simulation

## Note
Wi-Fi and cloud communication are part of the firmware design.
Due to simulation limitations, IoT connectivity is not executed in Proteus.
