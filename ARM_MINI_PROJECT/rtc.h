#include"types.h"   // Custom data types (u32, S32, etc.)

// ===================== RTC INITIALIZATION =====================

// Initialize RTC peripheral
// Configures prescaler, clock source, and enables RTC
void RTC_Init(void);


// ===================== TIME FUNCTIONS =====================

// Read current time from RTC registers
// hour, minute, second returned using pointers
void GetRTCTimeInfo (S32*, S32*, S32*);

// Display time on LCD or serial output
void DisplayRTCTime (u32, u32, u32);

// Set RTC time (hour, minute, second)
void SetRTCTimeInfo (u32, u32, u32);


// ===================== DATE FUNCTIONS =====================

// Read current date from RTC registers
// date, month, year returned using pointers
void GetRTCDateInfo (S32*, S32*, S32*);

// Display date on LCD
void DisplayRTCDate (u32, u32, u32);

// Set RTC date (date, month, year)
void SetRTCDateInfo (u32, u32, u32);


// ===================== DAY (WEEKDAY) FUNCTIONS =====================

// Read current day ( depending on configuration)
void GetRTCDay (S32*);

// Display current weekday
void DisplayRTCDay (u32);

// Set weekday value
void SetRTCDay (u32);


// ===================== USER INTERFACE FUNCTIONS =====================

// Edit RTC time/date through keypad input
void E_RTC(void);

// Edit medicine reminder time
void E_MEDICINE_TIME(void);


// ===================== UTILITY FUNCTIONS =====================

// Read numeric value from keypad
// Used for entering time/date values
S32 Readnum(void);

// Compare current RTC time with stored medicine reminder time
// If matched ? trigger buzzer/LED alert
void compare_rtc_with_med_time(void);
