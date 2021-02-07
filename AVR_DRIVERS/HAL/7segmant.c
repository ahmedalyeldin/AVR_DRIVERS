/*
 * _7segmant.c
 *
 * Created: 02-12-2020 13:39:39
 *  Author: ahmed
 */ 
#define F_CPU 8000000
#include "SevenSegment.h"
#include "DIO_Interface.h"
#include "util/delay.h"
#define SEGMENT_PORT PA
#define ENABLE_PIN1 PINC6
#define ENABLE_PIN2 PINC7


void SEVENSEGMENT_COUNT(void)
{
	int arr_cathod[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	int arr_anode [10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

	for(int i=0;i<10 ; i++)
	{
		DIO_WritePort(SEGMENT_PORT,arr_anode[i]);
		_delay_ms(500);
	}
}
void SEVENSEGMENT_print(int number)
{
	int arr_cathod[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	int arr_anode [10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
	int x1,x2;
	x1 = number%10;
	x2 = number/10;
	DIO_WritePin(ENABLE_PIN1,HIGH);
	DIO_WritePort(SEGMENT_PORT,(arr_cathod[number%10])<<1);
	DIO_WritePin(ENABLE_PIN2,LOW);
	_delay_ms(1);
	DIO_WritePin(ENABLE_PIN2,HIGH);
	DIO_WritePort(SEGMENT_PORT,(arr_cathod[number/10])<<1);
	DIO_WritePin(ENABLE_PIN1,LOW);
	_delay_ms(1);
	
}
void SEVENSEGMENT_print1(int n,unsigned char* x,unsigned char* x0)
{
	int arr[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	int x1,x2;
	x1 = n%10;
	x2 = n/10;
	
	*x0 = arr[x1];
	*x = arr[x2];
	
	
}