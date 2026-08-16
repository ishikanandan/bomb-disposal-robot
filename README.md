# Bomb Disposal Robot

A remotely operated robotic system designed for simulated hazardous-object handling. The project combines a mobile robotic platform, a 4-DOF robotic arm, Bluetooth-based control, and real-time video surveillance.

## Project Overview

This project was developed as a Real-Time Research Based Project during the second year of B.Tech Mechatronics Engineering.

The system is designed to allow an operator to remotely navigate a robotic platform and manipulate simulated hazardous objects while monitoring the surroundings through a camera.

The project explores how robotics and remote operation can be used to reduce direct human exposure in hazardous environments.

## Key Features

- Remotely operated robotic platform
- 4-DOF robotic arm for object manipulation
- Bluetooth-based control
- Real-time video surveillance
- Motor-driven mobile platform
- Simulated hazardous-object handling

## Hardware

- Arduino UNO
- L298N motor driver
- HC-05 Bluetooth module
- 12 V battery
- DC geared motors
- 4-DOF robotic arm
- Camera module
- LEDs and resistors
- Chassis and mechanical components

## System Architecture

The system consists of three main sections:

1. **Mobile Platform**  
   Provides movement and navigation of the robot.

2. **Robotic Manipulation System**  
   A 4-DOF robotic arm is used to reach and manipulate objects.

3. **Surveillance and Remote Operation**  
   Bluetooth-based control enables remote operation, while the camera provides live visual feedback.

## Working Principle

1. The operator sends control commands to the robotic platform.
2. The mobile platform moves according to the received commands.
3. The robotic arm is positioned to interact with the target object.
4. The camera provides real-time visual feedback to the operator.
5. The operator can remotely monitor and control the robot during simulated hazardous-object handling.

## Technical Challenge

Color recognition was initially considered as part of the object/wire identification approach. During development, the team encountered reliability issues with this method.

The project therefore explored alternative approaches based on physical characteristics such as resistance, capacitance, and magnetic-field behavior rather than relying solely on color recognition.

This highlighted the importance of evaluating sensing approaches under practical conditions rather than relying only on their theoretical suitability.

## Project Outcome

The project demonstrated the integration of mechanical systems, embedded control, wireless communication, robotic manipulation, and remote visual monitoring into a single robotic platform.

It provided practical exposure to robotic system assembly, motor control, remote operation, and the challenges involved in designing systems for hazardous-environment applications.

## Applications

Potential applications of the concept include:

- Hazardous-object handling
- Remote inspection
- Disaster-response robotics
- Industrial inspection
- Remote manipulation in hazardous environments
- Bomb-disposal training and simulation

## Project Images

Project photographs and supporting documentation are included in this repository.

## Project Presentation

[View Project Presentation](Bomb-Disposal-Robot-Project.pdf)

## Project Details

**Project Type:** Real-Time Research Based Project  
**Year:** Second Year B.Tech  
**Branch:** Mechatronics Engineering
