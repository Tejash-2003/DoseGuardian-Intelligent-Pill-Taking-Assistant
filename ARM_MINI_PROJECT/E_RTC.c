#include"header.h"   // Include main project header (contains RTC, LCD, keypad definitions)

// External global variables (defined elsewhere)
extern S32 hour,min,sec,date,month,year,dob,day;

u8 op;        // Stores user selected option from keypad
u32 num=0;    // Temporary variable (currently unused in this function)

void E_RTC(void)
{
	  
  // ================= RTC EDIT MENU =================
  label: CmdLCD(CLEAR_DISP);              // Clear LCD display
	           CmdLCD(GOTO_LINE1_POS0);   // Move cursor to first line
	           StrLCD("1.H 2.M 3.S 4.D");  // Options: Hour, Minute, Second, Day
	           CmdLCD(GOTO_LINE2_POS0);   // Move to second line
	           StrLCD("5.d 6.M 7.Y 8.E");  // Options: Date, Month, Year, Exit
			   WRITENIBBLE(IOPIN1,16,0);  // Clear keypad buffer
			   while(ColStat());          // Wait until key is pressed
			   delay_ms(200);             // Debounce delay
			   op=Readkeyval();           // Read key value
			   CmdLCD(CLEAR_DISP);        // Clear LCD
			   CmdLCD(GOTO_LINE1_POS0);   // Move cursor to first line
								
			  switch(op)
	             {
	                case '1':  // ================= SET HOUR =================
						     StrLCD("SET HOUR(0-23)");
						     WRITENIBBLE(IOPIN1,16,0);
		                     while(ColStat());         // Wait for input
			                 hour=Readnum();          // Read numeric input
							 
							 // Validate hour range
							 if((hour>=0)&&(hour<=23))
							    HOUR=hour;            // Write to RTC hour register
						     else
							 {
								CmdLCD(CLEAR_DISP);
								CmdLCD(GOTO_LINE1_POS0);
							    StrLCD("INVALID INPUT");
								delay_s(1);
							 }
							 goto label;             // Return to menu

	                case '2':  // ================= SET MINUTE =================
							 StrLCD("SET MIN(0-59)");
							 WRITENIBBLE(IOPIN1,16,0);
		                     while(ColStat());
			                 min=Readnum();
							 
							 // Validate minute range
							 if((min>=0)&&(min<=59))
			                     MIN=min;             // Write to RTC minute register
   						  	 else
							 {
							  CmdLCD(CLEAR_DISP);
							  CmdLCD(GOTO_LINE1_POS0);
						      StrLCD("INVALID INPUT");
							  delay_s(1);
							 }
							 goto label;

	                case '3':  // ================= SET SECOND =================
							 StrLCD("SET SEC(0-59)");
							 WRITENIBBLE(IOPIN1,16,0);
		                     while(ColStat());
			                 sec=Readnum();
							 
							 // Validate second range
							 if((sec>=0)&&(sec<=59))	 
			                     SEC=sec;            // Write to RTC second register
							 else
							 {
							     CmdLCD(CLEAR_DISP);
							     CmdLCD(GOTO_LINE1_POS0);
							     StrLCD("INVALID INPUT");
							     delay_s(1);
							 }						
							 goto label;		   

	               case '4':  // ================= SET DAY (WEEKDAY) =================
							 StrLCD("SET DAY(0-6)");
							 WRITENIBBLE(IOPIN1,16,0);
		                     while(ColStat());
			                 day=Readnum();
							 
							 // Validate day range (0-6)
							 if((day>=0)&&(day<=6))
			                     DOW=day;           // Write to RTC Day Of Week register
							 else
							 {
							     CmdLCD(CLEAR_DISP); // Clear display
							     CmdLCD(GOTO_LINE1_POS0);
							     StrLCD("INVALID INPUT");
							     delay_s(1);
							 }
							 goto label;

			        case '5':  // ================= SET DATE =================
					         StrLCD("SET DATE(0-31)");
					         WRITENIBBLE(IOPIN1,16,0);
		                     while(ColStat());
		        	         date=Readnum();
							 
							 // Validate date range
							 if((date>=0)&&(date<=31))	 
			                     DOM=date;          // Write to RTC Day Of Month register
							 else
							 {
							     CmdLCD(CLEAR_DISP); // Clear display
							     CmdLCD(GOTO_LINE2_POS0);
							     StrLCD("INVALID INPUT");
							     delay_s(1);
							 }
							 goto label;

	                case '6':  // ================= SET MONTH =================
				             StrLCD("SET MONTH(0-12)");
				             WRITENIBBLE(IOPIN1,16,0);
		                     while(ColStat());
			                 month=Readnum();
							 
							 // Validate month range
							 if((month>=0)&&(month<=12))
		                         MONTH=month;      // Write to RTC Month register
 							 else
							 {
							     CmdLCD(CLEAR_DISP);
							     StrLCD("INVALID INPUT");
							     delay_s(1);
							 }
							 goto label;

	                case '7':  // ================= SET YEAR =================
				             StrLCD("SET YEAR(2025-4095)");
				             WRITENIBBLE(IOPIN1,16,0);
		                     while(ColStat());
		        	         year=Readnum();
							 
							 // Validate year range
							 if((year>=2025)&&(year<=4095))
			                     YEAR=year;         // Write to RTC Year register
							 else
							 {
							     CmdLCD(CLEAR_DISP); // Clear display
							     CmdLCD(GOTO_LINE2_POS0);
							     StrLCD("INVALID INPUT");
							     delay_s(1);
							 }
							 goto label;

	                case '8':  // ================= EXIT =================
				             CmdLCD(CLEAR_DISP); 
				             CmdLCD(GOTO_LINE1_POS0);
							 StrLCD("TIME SAVED");  // Confirmation message
							 break;                           	 

             	    default:  // ================= INVALID KEY =================
						     CmdLCD(CLEAR_DISP);
						     StrLCD("INVALID KEY");
				             delay_ms(500);
				             goto label;
         }
}
