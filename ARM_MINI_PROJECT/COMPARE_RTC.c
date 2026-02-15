#include "header.h"

extern S32 hour, min, sec, date, month, year, day, data[3];
// data[0] = medicine hour
// data[1] = medicine minute
// data[2] = medicine second

void compare_rtc_with_med_time(void)
{
    u8 flag1 = 0;        // Flag to check whether medicine was taken or not
    u32 delay = 100;     // Loop counter to keep alert active for some time

    // Compare current RTC time with stored medicine time
    if ((hour == data[0]) && (min == data[1]) && (sec == data[2]))
    {
        CmdLCD(CLEAR_DISP);   // Clear LCD before showing alert

        // Keep alert active for limited iterations
        while (--delay)
        {
            CmdLCD(GOTO_LINE1_POS0);
            StrLCD("TAKE MEDICINE");   // Display reminder message

            CLEARBIT(IOPIN1, LED);     // Turn OFF LED (active low assumed)
            SETBIT(IOSET1, BUZZER);    // Turn ON buzzer
            delay_ms(200);             // Small delay for buzzer ON duration

            // Turn OFF buzzer
            CLEARBIT(IOPIN1, BUZZER);

            // Check if SW2 button is pressed (active LOW switch)
            if (((IOPIN0 >> SW2) & 1) == 0)
            {
                delay_ms(100);         // Debounce delay

                // Wait until switch is released
                while (((IOPIN0 >> SW2) & 1) == 0);

                delay_ms(100);         // Debounce delay
                CLEARBIT(IOPIN1, BUZZER); // Ensure buzzer is OFF

                flag1 = 1;             // Mark medicine as taken

                CmdLCD(CLEAR_DISP);
                CmdLCD(GOTO_LINE1_POS0);
                StrLCD("MEDICINE INTAKE");

                CmdLCD(GOTO_LINE2_POS0);
                StrLCD("COMPLETED...!");  // Confirmation message

                delay_s(2);             // Display message for 2 seconds

                CmdLCD(CLEAR_DISP);
                break;                  // Exit alert loop
            }
        }

        // If user did NOT press switch within alert time
        if (flag1 == 0)
        {
            CLEARBIT(IOPIN1, BUZZER);  // Ensure buzzer is OFF             
            IOSET1|=(1<<LED);       // Turn ON LED (missed indication)
					  CmdLCD(CLEAR_DISP);
            CmdLCD(GOTO_LINE1_POS0);
            StrLCD("MEDICINE INTAKE");

            CmdLCD(GOTO_LINE2_POS0);
            StrLCD("MISSED...?");      // Missed alert message

            delay_s(2);                // Display message for 2 seconds


            CmdLCD(CLEAR_DISP);
        }
    }
}
