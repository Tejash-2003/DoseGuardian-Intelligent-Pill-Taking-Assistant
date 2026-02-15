#include"header.h"

S32 Readnum(void)
{
   S32 num=0;        // Variable to store the final number entered
   S8 key;           // Stores pressed key value
   S8 count=0;       // Counts number of digits entered

   label:            // Label used to restart input in case of wrong entry

   while(1)          // Infinite loop until user presses 'D'
   {
        // Move cursor to second line at position 'count'
        CmdLCD(GOTO_LINE2_POS0+count);

        // Make rows low to detect key press
        WRITENIBBLE(IOPIN1,16,0);

        // Wait until a key is pressed
        while(ColStat());

        delay_us(200);      // Small debounce delay

        key=Readkeyval();   // Read pressed key

        // If key is a numeric character (0–9)
        if((key>='0')&&(key<='9'))
        {
            if(count<10)    // Allow maximum 10 digits
            {
               CharLCD(key);                 // Display digit on LCD
               num=((num*10)+(key-48));      // Convert ASCII to integer and build number
               count++;                      // Increment digit counter
            }
        }

        // If 'D' key is pressed ? input complete
        else if(key=='D')
        {
            return num;      // Return the final number
        }

        // If '/' key is pressed ? Backspace operation
        else if(key=='/')                                    
        {
             num=num/10;     // Remove last digit from number
             count--;        // Move one position back

             CmdLCD(GOTO_LINE2_POS0+count);  // Move cursor back
             CharLCD(' ');                   // Erase digit on LCD
             CmdLCD(GOTO_LINE2_POS0+count);  // Reposition cursor
        }

        // If any other key is pressed ? Invalid input
        else 
        {
            CmdLCD(GOTO_LINE2_POS0);
            StrLCD("                ");   // Clear second line

            CmdLCD(GOTO_LINE2_POS0);
            StrLCD("WRONG INPUT");        // Display error message
            delay_ms(1000);

            CmdLCD(GOTO_LINE2_POS0);
            StrLCD("                 ");

            CmdLCD(GOTO_LINE2_POS0);
            StrLCD("SET AGAIN INPUT");    // Ask user to re-enter
            delay_ms(1000);

            CmdLCD(GOTO_LINE2_POS0);
            StrLCD("                 ");  // Clear line again

            num=0;        // Reset number
            count=0;      // Reset digit counter

            goto label;   // Restart input process
        }
   }
}
