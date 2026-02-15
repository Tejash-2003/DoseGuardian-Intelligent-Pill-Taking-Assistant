#include<LPC21XX.H>          // LPC21xx register definitions
#include"keypad.h"           // Keypad function declarations
#include"keypadDefines.h"    // Row/Column macros and LUT table

// ===================== KEYPAD INITIALIZATION =====================
void KeypadInit(void)
{
  // Configure Row pins (R0–R3) as OUTPUT
  // P1.16–P1.19 are used as row pins
  IODIR1 |= (1<<R0) | (1<<R1) | (1<<R2) | (1<<R3);
}


// ===================== CHECK COLUMN STATUS =====================
int ColStat(void)
{
  // Read column pins C0–C3
  // If all column inputs are HIGH (0xF), no key is pressed
  if(((IOPIN1>>C0)&0XF)==0XF)
      return 1;     // No key pressed
  else
      return 0;     // Key pressed
}


// ===================== READ KEY VALUE =====================
char Readkeyval(void)
{												 
  char Rowval, Colval;   // Row and Column index

  // Drive all rows LOW initially
  IOCLR1 = 15<<R0;

  // Wait until a key is pressed
  while(ColStat());

  // ================= ROW SCANNING =================

  // Activate Row 0 (LOW), set others HIGH
  IOCLR1 = 1<<R0;
  IOSET1 = ((1<<R1)|(1<<R2)|(1<<R3));

  // If any column becomes LOW ? key detected in row 0
  if(((IOPIN1>>C0)&0XF)!=0XF)
  {
      Rowval = 0;
      goto Colcheck;
  }

  // Activate Row 1
  IOCLR1 = 1<<R1;
  IOSET1 = ((1<<R0)|(1<<R2)|(1<<R3));
  if(((IOPIN1>>C0)&0XF)!=0XF)
  {
      Rowval = 1;
      goto Colcheck;
  }

  // Activate Row 2
  IOCLR1 = 1<<R2;
  IOSET1 = ((1<<R0)|(1<<R1)|(1<<R3));
  if(((IOPIN1>>C0)&0XF)!=0XF)
  {
      Rowval = 2;
      goto Colcheck;
  }

  // Activate Row 3
  IOCLR1 = 1<<R3;
  IOSET1 = ((1<<R0)|(1<<R1)|(1<<R2));
  if(((IOPIN1>>C0)&0XF)!=0XF)
  {
      Rowval = 3;
      goto Colcheck;
  }

  // ================= COLUMN DETECTION =================
  Colcheck:

  // Check which column is LOW
  if(((IOPIN1>>C0)&1)==0)
      Colval = 0;
  else if(((IOPIN1>>C1)&1)==0)
      Colval = 1;
  else if(((IOPIN1>>C2)&1)==0)
      Colval = 2;
  else if(((IOPIN1>>C3)&1)==0)
      Colval = 3;

  // Wait until key is released (all columns HIGH again)
  while(((IOPIN1>>C0)&0XF)!=0XF);

  // Return corresponding key value from Look-Up Table
  return (LUT[Rowval][Colval]);
}
