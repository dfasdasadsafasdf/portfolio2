# Arduino Safety Monitoring System

---

## Overview

This project is one of my first practical works with the **Arduino microcontroller**.  
The goal of the project was to learn the basic principles of **embedded systems and sensor interaction** by building a simple environmental safety monitoring system.

The system monitors several environmental parameters and reacts when potentially dangerous conditions are detected.

The Arduino continuously reads data from connected sensors and analyzes the data in real time.  
If sensor values exceed predefined thresholds, the system identifies the situation as dangerous.

When a risk is detected, the system:

- activates an LED warning signal  
- activates a buzzer alarm  
- displays a warning message on the LCD display  

Manual control buttons were also added for **system activation and emergency trigger**.

---

## Hardware

Components used in the project:

- Arduino Uno  
- MQ Gas Sensor  
- Temperature Sensor  
- Photoresistor (light sensor)  
- LCD Display (16x2)  
- Buzzer  
- LEDs  
- Push buttons  

---

## System Logic

1. Arduino reads data from sensors continuously  
2. Sensor values are compared with predefined thresholds  
3. If dangerous conditions are detected:
   - LED indicator turns on
   - buzzer alarm is activated
   - warning message appears on the LCD display  

The system can also be manually triggered using control buttons.

---

## Simulation

### Normal Operation

<img width="404" height="341" alt="111111111111111111" src="https://github.com/user-attachments/assets/c88ff749-a45c-4cc1-82d4-8106e7638b17" />

The LCD displays current sensor values.

---

### Alert Mode

<img width="410" height="349" alt="222222222222222222222222" src="https://github.com/user-attachments/assets/6483c36e-44f2-4b8d-b40a-2ef726a60e03" />

If sensor thresholds are exceeded, the system displays a warning and activates alarms.

---

## Features

- real-time environmental monitoring  
- threshold-based safety detection  
- LCD display with system status  
- buzzer and LED alarm system  
- manual control buttons  

---

## Project Status

The project is completed as a **basic embedded system prototype** demonstrating sensor monitoring and safety alert mechanisms.

---

<img width="404" height="341" alt="111111111111111111" src="https://github.com/user-attachments/assets/c88ff749-a45c-4cc1-82d4-8106e7638b17" />

<img width="410" height="349" alt="222222222222222222222222" src="https://github.com/user-attachments/assets/6483c36e-44f2-4b8d-b40a-2ef726a60e03" />


