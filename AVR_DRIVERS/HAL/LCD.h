/*
 * LCD.h
 *
 * Created: 03-12-2020 10:13:13
 *  Author: ahmed
 */ 

#ifndef LCD_H_
#define LCD_H_
#define F_CPU 8000000
#define RS PINA7
#define EN PINB0
#define _4_BIT 0
#define _8_bit 1

/*********************************8_BIT******************************/
#define LCD_PORT PA
/*********************************4_BIT******************************/
#define D4 PINA3
#define D5 PINA4
#define D6 PINA5
#define D7 PINA6



#include "DIO_Interface.h"
#include "util/delay.h"

void LCD_Init(void);
void LCD_WriteData(u8 data);
void LCD_WriteCommand(u8 command);
void LCD_WriteChar(u8 ch);
void LCD_WriteNumber(s64 num);
void LCD_WriteNumber4digits(u16 num);
void LCD_WriteBinary(u16 num);
void LCD_SetCursor(u8 line,u8 coloumn);
void LCD_Clr(void);
void LCD_AsciCount(void);
void LCD_StringAnimation(u8*str);
void LCD_WriteString(u8*str);
void LCD_Create_Character(u8* pattern,u8 location);
void LCD_WriteHex(u16 num);



#endif /* LCD_H_ */

