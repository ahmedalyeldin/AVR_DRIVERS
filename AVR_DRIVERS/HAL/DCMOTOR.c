/*
 * DCMOTOR.c
 *
 * Created: 02-12-2020 13:39:51
 *  Author: ahmed
 */
#include "DCMOTOR.h"
#include "DIO_Interface.h"

void Motor_CCW(void)
{
	DIO_WritePin(PINA0,HIGH);
	DIO_WritePin(PINA1,LOW);
}
void Motor_CW(void)
{

		DIO_WritePin(PINA0,LOW);
		DIO_WritePin(PINA1,HIGH);
}
void Motor_stop(void)
{
		DIO_WritePin(PINA0,LOW);
		DIO_WritePin(PINA1,LOW);
}

void Motor_CW_Speed_Control(u8 speed)
{
	DIO_WritePin(PINA0,LOW);
	DIO_WritePin(PINA1,HIGH);
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	TIMER0_OC0Mode(OC0_NON_INVERTING);
	TCNT0 = 0;
	OCR0 = (speed/100.00)*255;
}
void Motor_CCW_Speed_Control(u8 speed)
{
	DIO_WritePin(PINA0,HIGH);
	DIO_WritePin(PINA1,LOW);
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	TIMER0_OC0Mode(OC0_NON_INVERTING);
	TCNT0 = 0;
	OCR0 = (speed/100.00)*255;
}