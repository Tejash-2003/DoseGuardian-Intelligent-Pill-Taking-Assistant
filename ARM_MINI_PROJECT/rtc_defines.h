#ifndef RTC_DEFINES_H
#define RTC_DEFINES_H

// ===================== CLOCK CONFIGURATION MACROS =====================

// External crystal oscillator frequency (12 MHz)
#define FOSC 12000000

// CPU Clock (CCLK)
// If PLL multiplier = 5, then:
// CCLK = 5 × FOSC = 60 MHz
#define CCLK (5*FOSC)    

// Peripheral Clock (PCLK)
// In LPC21xx, PCLK = CCLK / 4 (default divider)
#define PCLK (CCLK/4) 

// ===================== RTC PRESCALER MACROS =====================

// RTC requires 32.768 kHz clock for accurate time counting.
// These values are used to generate 1-second tick from PCLK.

// Integer portion of prescaler
#define PREINT_VAL ((PCLK/32768)-1)

// Fractional portion of prescaler
#define PREFRAC_VAL (PCLK-(PREINT_VAL+1)*32768)

// ===================== CCR (Clock Control Register) BITS =====================

// Enable RTC (Start time counting)
#define RTC_ENABLE  (1<<0)

// Reset RTC counters
#define RTC_RESET   (1<<1)

// Select clock source (0 = internal, 1 = external 32.768kHz crystal)
#define RTC_CLKSRC  (1<<4)

//#define CPU_LPC2148   // Optional macro to specify MCU type (currently commented)

#endif
