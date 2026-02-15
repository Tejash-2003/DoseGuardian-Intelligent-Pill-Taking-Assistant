#include"header.h"   // Include main project header

// External global variables (defined in main file)
extern S32 hour,min,sec,date,month,year,dob,day;   // RTC current time/date
extern S32 Hour[TOTAL_MED],Min[TOTAL_MED],Sec[TOTAL_MED]; // Medicine time arrays
u8 ch,slot;         // ch ? key pressed, slot ? medicine time slot index
extern u32 i;       // External loop variable
u32 data[3];        // Temporary array to store entered hour, min, sec

void E_MEDICINE_TIME(void)
{  
               // ================= SELECT MEDICINE SLOT =================
			   test:CmdLCD(CLEAR_DISP);             // Clear LCD
			        CmdLCD(GOTO_LINE1_POS0);         // Move cursor to line 1
					StrLCD("1.MOR  2.AFT");           // Morning & Afternoon options
					CmdLCD(GOTO_LINE2_POS0);         // Move to line 2
					StrLCD("3.NIGHT 4.EXIT");        // Night & Exit options
					WRITENIBBLE(IOPIN1,16,0);        // Clear keypad buffer
					while(ColStat());               // Wait for key press
					delay_ms(200);                  // Debounce delay
                    ch=Readkeyval();                // Read pressed key

			        // Assign slot index based on selection
			        if(ch=='1')
			        slot=0;      // Morning slot
			        else if(ch=='2')
			        slot=1;      // Afternoon slot
			        else if(ch=='3')
			        slot=2;      // Night slot
			        else if(ch=='4')
			        goto test;   // If exit, reload same menu

	  // ================= EDIT TIME MENU =================
	  label:CmdLCD(CLEAR_DISP);             
		   CmdLCD(GOTO_LINE1_POS0);
	       StrLCD("1.H 2.M 3.S");          // Select Hour, Minute, Second
		   CmdLCD(GOTO_LINE2_POS0);
		   StrLCD("4.Save 5.Exit");        // Save or Exit option
		   WRITENIBBLE(IOPIN1,16,0);       // Clear keypad
		   while(ColStat());              // Wait for key press
		   delay_s(1);                    // Small delay
		   ch=Readkeyval();               // Read key
		   CmdLCD(CLEAR_DISP);
		   CmdLCD(GOTO_LINE1_POS0);

		switch(ch)
		{
	        case '1':   // ================= SET HOUR =================
		             WRITENIBBLE(IOPIN1,16,0);
		             while(ColStat());
			         StrLCD("SET HOUR(0-23)");				    		            
			         Hour[slot]=Readnum();     // Read hour input
					 
					 // Validate input range
					 if((Hour[slot]<0)&&(Hour[slot]>23))
					 {
					     CmdLCD(CLEAR_DISP);
					     CmdLCD(GOTO_LINE1_POS0);
					     StrLCD("INVALID INPUT");
					     delay_s(1);
					 }
					 else
					 {
					     data[0]=Hour[slot];  // Store valid hour
			             goto label;          // Return to edit menu
					 }

	        case '2':   // ================= SET MINUTE =================
		             WRITENIBBLE(IOPIN1,16,0);
		             while(ColStat());
			         StrLCD("SET MIN(0-59)");
		             Min[slot]=Readnum();      // Read minute input
					 
					 // Validate minute range
					 if((Min[slot]<0)&&(Min[slot]>59))
					 {
					     CmdLCD(CLEAR_DISP);
					     CmdLCD(GOTO_LINE1_POS0);
					     StrLCD("INVALID INPUT");
					 }
					 else
					 {
					     data[1]=Min[slot];   // Store valid minute
					     goto label;          // Return to edit menu
					 }

	        case '3':   // ================= SET SECOND =================
			         StrLCD("SET SEC(0-59)");
			         WRITENIBBLE(IOPIN1,16,0);
		             while(ColStat());
			         Sec[slot]=Readnum();      // Read seconds input
					 
					 // Validate seconds range
					 if((Sec[slot]<0)&&(Sec[slot]>59))
					 {
					     CmdLCD(CLEAR_DISP);
					     CmdLCD(GOTO_LINE1_POS0);
					     StrLCD("INVALID INPUT");
					     delay_s(1);
					 }
                     else
					 {
					     data[1]=Sec[slot];   // Store valid second
			             goto label;          // Return to edit menu
					 }

	    	case '4':   // ================= SAVE TIME =================
			         CmdLCD(CLEAR_DISP);
			         CmdLCD(GOTO_LINE1_POS0);
			         StrLCD("TIME SAVED");    // Confirmation message
					      CmdLCD(CLEAR_DISP);
					 
					 // Display saved time
					     DisplayRTCTime(data[0],data[1],data[2]);
					     delay_ms(1000);
					     CmdLCD(CLEAR_DISP);
		           goto label;              // Return to edit menu

			case '5':   // ================= EXIT =================
			         CmdLCD(CLEAR_DISP);
			         break;

		    default:   // ================= INVALID KEY =================
		             CmdLCD(CLEAR_DISP);
		             StrLCD("INVALID KEY");
					       delay_s(1);		
					       CmdLCD(CLEAR_DISP);	        
			          goto label;
	      }
}
