#ifndef DELAY_H          // Include guard start
#define DELAY_H

#include"types.h"        // Contains custom data types (u32 etc.)

// ===================== DELAY FUNCTION DECLARATIONS =====================

// Generate delay in microseconds
// Used for small timing requirements (LCD enable pulse, sensor timing etc.)
void delay_us(u32);

// Generate delay in milliseconds
// Commonly used for debouncing, LCD commands, menu delays
void delay_ms(u32);

// Generate delay in seconds
// Used for long delays (buzzer alert, wait state etc.)
void delay_s(u32);

#endif   // Include guard end
