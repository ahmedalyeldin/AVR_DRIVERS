/*
 * Stepper.c
 *
 * Created: 08-12-2020 11:00:07
 *  Author: WENUS
 */ 

#define F_CPU 8000000
#include <util/delay.h>
#include "Stepper.h"

void STEPPER_BiPoler_CCW(void)
{

	DIO_WritePin(COIL1_A,LOW);
	DIO_WritePin(COIL1_B,LOW);
	DIO_WritePin(COIL2_A,HIGH);
	DIO_WritePin(COIL2_B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1_A,LOW);
	DIO_WritePin(COIL1_B,HIGH);
	DIO_WritePin(COIL2_A,LOW);
	DIO_WritePin(COIL2_B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1_A,LOW);
	DIO_WritePin(COIL1_B,LOW);
	DIO_WritePin(COIL2_A,LOW);
	DIO_WritePin(COIL2_B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1_A,HIGH);
	DIO_WritePin(COIL1_B,LOW);
	DIO_WritePin(COIL2_A,LOW);
	DIO_WritePin(COIL2_B,LOW);
	_delay_ms(DELAY);
}
void STEPPER_BiPoler_CW(void)
{

		DIO_WritePin(COIL1_A,LOW);
		DIO_WritePin(COIL1_B,LOW);
		DIO_WritePin(COIL2_A,LOW);
		DIO_WritePin(COIL2_B,HIGH);
		_delay_ms(DELAY);
		DIO_WritePin(COIL1_A,LOW);
		DIO_WritePin(COIL1_B,HIGH);
		DIO_WritePin(COIL2_A,LOW);
		DIO_WritePin(COIL2_B,LOW);
		_delay_ms(DELAY);
		DIO_WritePin(COIL1_A,LOW);
		DIO_WritePin(COIL1_B,LOW);
		DIO_WritePin(COIL2_A,HIGH);
		DIO_WritePin(COIL2_B,LOW);
		_delay_ms(DELAY);
		DIO_WritePin(COIL1_A,HIGH);
		DIO_WritePin(COIL1_B,LOW);
		DIO_WritePin(COIL2_A,LOW);
		DIO_WritePin(COIL2_B,LOW);
			_delay_ms(DELAY);
		
}
void STEPPER_UnPoler_CCW(void)
{

	DIO_WritePin(COIL1_A,HIGH);
	DIO_WritePin(COIL1_B,LOW);
	DIO_WritePin(COIL2_A,LOW);
	DIO_WritePin(COIL2_B,LOW);
	_delay_ms(DELAY1);
	DIO_WritePin(COIL1_A,LOW);
	DIO_WritePin(COIL1_B,HIGH);
	DIO_WritePin(COIL2_A,LOW);
	DIO_WritePin(COIL2_B,LOW);
	_delay_ms(DELAY1);
	DIO_WritePin(COIL1_A,LOW);
	DIO_WritePin(COIL1_B,LOW);
	DIO_WritePin(COIL2_A,HIGH);
	DIO_WritePin(COIL2_B,LOW);
	_delay_ms(DELAY1);
	DIO_WritePin(COIL1_A,LOW);
	DIO_WritePin(COIL1_B,LOW);
	DIO_WritePin(COIL2_A,LOW);
	DIO_WritePin(COIL2_B,HIGH);
	_delay_ms(DELAY1);
}
void STEPPER_UnPoler_CW(void)
{
	
	DIO_WritePin(COIL1_A,LOW);
	DIO_WritePin(COIL1_B,LOW);
	DIO_WritePin(COIL2_A,LOW);
	DIO_WritePin(COIL2_B,HIGH);
	_delay_ms(DELAY1);
	DIO_WritePin(COIL1_A,LOW);
	DIO_WritePin(COIL1_B,LOW);
	DIO_WritePin(COIL2_A,HIGH);
	DIO_WritePin(COIL2_B,LOW);
	_delay_ms(DELAY1);
	DIO_WritePin(COIL1_A,LOW);
	DIO_WritePin(COIL1_B,HIGH);
	DIO_WritePin(COIL2_A,LOW);
	DIO_WritePin(COIL2_B,LOW);
	_delay_ms(DELAY1);
	DIO_WritePin(COIL1_A,HIGH);
	DIO_WritePin(COIL1_B,LOW);
	DIO_WritePin(COIL2_A,LOW);
	DIO_WritePin(COIL2_B,LOW);
	_delay_ms(DELAY1);
	
}
void STEPPER_RotatByAngel_UnPoler_CCW(u16 degre)
{
	/* one Step = 2 degree*/ 
	u16 angel1=degre/4;
	for(u16 i=0;i<angel1;i++)
	STEPPER_UnPoler_CCW();
}
void STEPPER_RotatByAngel_UnPoler_CW(u16 degre)
{
	/* one Step = 2 degree*/
	u16 angel1=degre/4;
	for(u16 i=0;i<angel1;i++)
	STEPPER_UnPoler_CW();
}
void STEPPER_RotatByCycel_UnPoler_CCW(u16 cycel)
{
	for(u16 i=0;i<(cycel*90);i++)
		STEPPER_UnPoler_CCW();
}
void STEPPER_RotatByCycel_UnPoler_CW(u16 cycel)
{
	for(u16 i=0;i<(cycel*90);i++)
	STEPPER_UnPoler_CW();
}
