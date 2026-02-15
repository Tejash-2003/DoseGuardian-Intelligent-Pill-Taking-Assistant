#ifndef LCD_H
#define LCD_H

#include"types.h"

void InitLCD(void);
void CmdLCD(u8);
void CharLCD(s8);
void StrLCD(s8 *);
void IntLCD(s32);
void FloatLCD(f32,u32);
void WriteToCGRAM(void);
void Display_rtc(void);
void Display_invalid(void);

#endif
