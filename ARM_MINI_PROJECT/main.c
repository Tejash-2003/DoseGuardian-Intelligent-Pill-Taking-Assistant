#include"Header.h"   // Include user-defined header file (contains macros, typedefs, function prototypes)

/* Global variables for RTC current time and date */
S32 hour, min, sec;           // Current time variables
S32 date, month, year;        // Current date variables
S32 dob, day;                 // Additional date variables (day of birth / weekday)

/* Arrays to store medicine reminder time (Multiple medicines supported) */
S32 Hour[TOTAL_MED], Min[TOTAL_MED], Sec[TOTAL_MED];  // Medicine time storage

u8 choice;   // Variable to store user menu choice
u8 i;        // Loop variable

int main()
{
   // ================= GPIO CONFIGURATION =================
   // Configure LED and BUZZER pins as OUTPUT
   IODIR1 |= ((1<<BUZZER) | (1<<LED));

   // ================= PERIPHERAL INITIALIZATION =================
   InitLCD();        // Initialize LCD display
   KeypadInit();     // Initialize Keypad
   RTC_Init();       // Initialize Real Time Clock

   // ================= SET INITIAL RTC TIME =================
   SetRTCTimeInfo(11,30,30);     // Set initial time: 11:30:10
   SetRTCDateInfo(18,12,2025);   // Set initial date: 18/12/2025
   SetRTCDay(4);                 // Set day (example: Thursday if 0=Sunday)

   while(1)
   {  
label:  // Label used to return back to RTC display after menu operations

      // Display current Date and Time continuously on LCD
      DispLCD_rtc();

      // Check if SW1 button is pressed (active low)
      if(((IOPIN0>>SW1)&1) == 0)
      {
          delay_ms(100);  // Debounce delay

          // Wait until switch is released
          while(((IOPIN0>>SW1)&1) == 0);

          // Clear LCD and show menu options
          CmdLCD(CLEAR_DISP);
          CmdLCD(GOTO_LINE1_POS0);
          StrLCD("1.E.RTC 3.EXIT");   // Option 1 and 3
          CmdLCD(GOTO_LINE2_POS0);
          StrLCD("2.E.MEDICINETIME"); // Option 2

          // Clear keypad previous input
          WRITENIBBLE(IOPIN1,16,0);

          // Wait until any key is pressed
          while(ColStat());

          // Read pressed key value
          choice = Readkeyval();
          delay_ms(200);  // Small delay for stability

          // ================= MENU SELECTION =================
          switch(choice)
          {
              case '1':   // Edit RTC Time/Date
                        E_RTC();
                        CmdLCD(CLEAR_DISP);
                        goto label;   // Return to RTC display
              
              case '2':   // Edit Medicine Reminder Time
                        CmdLCD(CLEAR_DISP);
                        E_MEDICINE_TIME();
                        break;

              case '3':   // Exit option (just break)
                        break;

              default:    // Invalid input handling
                        CmdLCD(CLEAR_DISP);
                        CmdLCD(GOTO_LINE1_POS0);
                        StrLCD("INVALID INPUT");
                        delay_ms(1000);
                        CmdLCD(CLEAR_DISP);
          }
      }

      // Compare current RTC time with stored medicine time
      // If matched ? buzzer/LED alert (inside function)
      compare_rtc_with_med_time();
   }	  
}
