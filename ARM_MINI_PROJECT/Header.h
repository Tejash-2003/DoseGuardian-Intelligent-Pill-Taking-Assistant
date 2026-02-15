#ifndef HEADERS_H     // If HEADERS_H is not defined
#define HEADERS_H     // Define HEADERS_H to prevent multiple inclusion

// ===================== MCU HEADER =====================
// Contains register definitions for LPC21xx ARM7 microcontroller
#include<LPC21XX.H>

// ===================== PROJECT HEADER FILES =====================
#include"rtc_defines.h"   // RTC register definitions and macros
#include"LCD.h"           // LCD function declarations
#include"keypad.h"        // Keypad function declarations
#include"types.h"         // Custom data types (S32, u8, etc.)
#include"lcddefines.h"    // LCD command macros (CLEAR_DISP, GOTO_LINE, etc.)
#include"delay.h"         // Delay function declarations
#include"defines.h"       // General project macros
#include"rtc.h"           // RTC function prototypes

// ===================== PIN DEFINITIONS =====================
// GPIO pin numbers used in the project

#define LED 25        // LED connected to P1.25
#define SW1 16        // Switch 1 connected to P0.16
#define SW2 17        // Switch 2 connected to P0.17
#define BUZZER 26     // Buzzer connected to P1.26

// ===================== PROJECT CONFIGURATION =====================
#define TOTAL_MED 3   // Maximum number of medicine reminders supported

#endif   // End of include guard
