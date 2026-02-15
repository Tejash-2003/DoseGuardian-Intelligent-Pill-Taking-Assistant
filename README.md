# DoseGuardian-Intelligent-Pill-Taking-Assistant
DoseGuardian is a real-time embedded healthcare reminder system developed using LPC21xx ARM7 microcontroller and Embedded C. The system uses a Real-Time Clock (RTC) to track current time and compares it with a user-configured medicine schedule. When both times match, the system generates an alert using an LCD display, LED, and buzzer.
This project demonstrates practical implementation of real-time systems, peripheral interfacing, and modular firmware design.

🎯 Objective

To design and implement a standalone embedded system that:

Tracks real time using RTC

Allows user to configure medicine schedule

Automatically reminds user at the correct time

Operates without internet or mobile dependency

⚙️ System Features

RTC-based real-time clock monitoring

Menu-driven LCD user interface

Keypad-based time configuration

Automatic medicine reminder alert

LED and buzzer notification

Modular multi-file Embedded C implementation

Simulated and verified using Proteus

🧩 Hardware Components

LPC2124 / LPC21xx ARM7 Microcontroller

RTC (Real-Time Clock)

16×2 LCD Display

4×4 Matrix Keypad

LED

Buzzer / Speaker

🛠 Software Tools Used

Embedded C

Keil µVision IDE

Proteus 8 Professional (Simulation)

Flash Magic

🔍 Working Principle

1️⃣ System Initialization

LCD, RTC, and keypad peripherals are initialized. Default menu is displayed on the LCD.

2️⃣ RTC Configuration

User sets current hour, minute, second, date.

Values are written into RTC registers.

File Reference: E_RTC.c

3️⃣ Medicine Time Setup

User configures medicine intake time using keypad.

Values are stored for comparison.

File Reference: E_MEDICINE_TEST.c

4️⃣ Continuous Time Monitoring

RTC continuously updates current time.

System periodically reads RTC registers.

File Reference: RTC1.c

5️⃣ Time Comparison Logic

Current RTC time is compared with medicine time.

When hour, minute, and second match → alert condition triggered.

File Reference:COMPARE_RTC.c

6️⃣ Alert Mechanism

LCD displays reminder message.

LED glows.

Buzzer activates.

User acknowledges using keypad.

System resets alert and continues monitoring.

🧠 Embedded Concepts Demonstrated

Embedded C Programming

RTC Register Programming

LCD Interfacing

Keypad Matrix Scanning

Real-Time Comparison Logic

Modular Firmware Architecture

Input Validation Techniques

🏥 Applications

Smart healthcare systems

Assistive medical devices

Elderly care reminder systems

Real-time embedded monitoring applications

🚀 Future Enhancements

Support for multiple medicine schedules

EEPROM-based persistent storage

GSM / Bluetooth alert system

Mobile application integration

👨‍💻 Developed by

YELAMANCHILI TEJASH KUMAR

Embedded Systems Engineer

Skills: Embedded C | LPC21xx | RTC | Real-Time Systems | Proteus
