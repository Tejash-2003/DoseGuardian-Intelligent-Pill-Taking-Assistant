#ifndef LCD_DEFINES_H     // Include guard start
#define LCD_DEFINES_H

// ===================== LCD DATA BUS =====================

// 0xff ? 8-bit data bus mask (P0.0 to P0.7)
// Used when LCD is connected in 8-bit mode
#define LCD_data 0xff    // LCD Data lines mask

// ===================== LCD CONTROL PINS =====================

// Register Select pin
// RS = 0 ? Command register
// RS = 1 ? Data register
// Connected to P0.5
#define RS 5   // RS -> P0.5

// Enable pin
// Generates pulse to latch command/data into LCD
// Connected to P0.6
#define EN 6   // EN -> P0.6

// Read/Write pin
// RW = 0 ? Write operation
// RW = 1 ? Read operation
// Connected to P0.7
#define RW 7   // RW -> P0.7

// ===================== LCD COMMAND MACROS =====================

// Move cursor to Line 1, Position 0
// DDRAM address = 0x80
#define GOTO_LINE1_POS0  0X80

// Move cursor to Line 2, Position 0
// DDRAM address = 0xC0
#define GOTO_LINE2_POS0  0XC0

// Clear entire display and return cursor to home
#define CLEAR_DISP       0X01

#endif   // Include guard end
