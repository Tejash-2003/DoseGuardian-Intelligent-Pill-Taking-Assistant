#include"header.h"

extern S32 hour,min,sec,date,month,year,dob,day;

/*---------------- LCD INITIALIZATION ----------------*/

void InitLCD(void)
{
  // Configure P0.8–P0.15 as OUTPUT (LCD Data Pins D0–D7)
  IODIR0 |= LCD_data << 8;

  // Configure P0.4–P0.6 as OUTPUT (RS, RW, EN control pins)
  IODIR0 |= (1<<RS) | (1<<RW) | (1<<EN);

  delay_ms(20);      // Minimum 15ms delay after power ON

  // Initialization sequence for 8-bit mode (as per HD44780 datasheet)
  CmdLCD(0x30);      // Force 8-bit mode
  delay_ms(8);       // Minimum 5ms delay

  CmdLCD(0x30);      // Repeat
  delay_ms(1);

  CmdLCD(0x30);      // Repeat again
  delay_ms(1);

  CmdLCD(0x38);      // 8-bit mode, 2 lines, 5x7 font
  CmdLCD(0x08);      // Display OFF
  CmdLCD(CLEAR_DISP);// Clear display
  CmdLCD(0x06);      // Auto increment cursor
  CmdLCD(0x0C);      // Display ON, Cursor ON, Blink ON
}

/*---------------- LOW LEVEL LCD WRITE FUNCTION ----------------*/

void DispLCD(u8 val)
{
  IOCLR0 = 1<<RW;          // Select WRITE operation (RW = 0)

  WRITEBYTE(IOPIN0,8,val); // Put data on P0.8–P0.15

  IOSET0 = 1<<EN;          // EN = 1 (Latch data)
  delay_us(1);             // Minimum 450ns enable pulse width
  IOCLR0 = 1<<EN;          // EN = 0

  delay_ms(2);             // Wait for command execution
}

/*---------------- SEND COMMAND TO LCD ----------------*/

void CmdLCD(u8 Cmd)
{
  IOCLR0 = 1<<RS;   // RS = 0 ? Instruction Register selected
  DispLCD(Cmd);     // Send command
}

/*---------------- SEND DATA (CHARACTER) TO LCD ----------------*/

void CharLCD(S8 dat)
{
  IOSET0 = 1<<RS;   // RS = 1 ? Data Register selected
  DispLCD(dat);     // Send character
}

/*---------------- DISPLAY STRING ----------------*/

void StrLCD(S8 *ptr)
{
  while(*ptr != '\0')   // Until NULL terminator
  {
    CharLCD(*ptr);      // Print character
    ptr++;              // Move to next character
  }
}

/*---------------- DISPLAY INTEGER ----------------*/

void IntLCD(S32 num)
{
   S8 a[10];   // Array to store digits
   S32 i = 0;

   if(num == 0)
   {
     CharLCD(0 + 48);  // Print '0'
   }
   else
   {
     if(num < 0)       // Handle negative numbers
     {
        CharLCD('-');
        num = -num;
     }

     // Convert integer to ASCII (reverse order)
     while(num)
     {
       a[i++] = num % 10 + 48; // Convert digit to ASCII
       num = num / 10;
     }

     --i;

     // Print digits in correct order
     for(; i >= 0; i--)
     {
       CharLCD(a[i]);
     }
   }
}

/*---------------- DISPLAY FLOAT ----------------*/

void F32LCD(F32 num, u32 NDP)
{
    S8 i, n;

    if(num < 0.0)
    {
       CharLCD('-');
       num = -num;
    }

    n = num;           // Extract integer part
    IntLCD(n);         // Print integer part

    CharLCD('.');      // Print decimal point

    // Print fractional part up to NDP digits
    for(i = 0; i < NDP; i++)
    {
       num = (num - n) * 10;
       n = num;
       CharLCD(n + 48);
    }
}

/*---------------- DISPLAY RTC INFORMATION ----------------*/

void DispLCD_rtc(void)
{
    // Get current time from RTC
    GetRTCTimeInfo(&hour, &min, &sec);
    DisplayRTCTime(hour, min, sec);

    // Get current date from RTC
    GetRTCDateInfo(&date, &month, &year);
    DisplayRTCDate(date, month, year);

    // Get current day of week
    GetRTCDay(&day);
    DisplayRTCDay(day);
}
