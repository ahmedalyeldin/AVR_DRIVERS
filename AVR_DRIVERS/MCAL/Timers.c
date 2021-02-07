/*
 * Timers.c
 *
 * Created: 17-12-2020 09:36:52
 *  Author: ahmed
 */ 
#include "Timers.h"


void TIMER0_Init(Timer0Mode_type mode,Timer0Scaler_type scaler)
{
	switch (mode)
	{
		case TIMER0_NORMAL_MODE:
		CLR_bit(TCCR0,WGM00);
		CLR_bit(TCCR0,WGM01);
		break;
		case TIMER0_PHASECORRECT_MODE:
		SET_bit(TCCR0,WGM00);
		CLR_bit(TCCR0,WGM01);
		break;
		case TIMER0_CTC_MODE:
		CLR_bit(TCCR0,WGM00);
		SET_bit(TCCR0,WGM01);
		break;
		case TIMER0_FASTPWM_MODE:
		SET_bit(TCCR0,WGM00);
		SET_bit(TCCR0,WGM01);
		break;
	}
	TCCR0&=0XF8;//0b11111000
	TCCR0|=scaler;
}

void TIMER0_OC0Mode(OC0Mode_type mode)
{
	switch (mode)
	{
		case OC0_DISCONNECTED:
		CLR_bit(TCCR0,COM00);
		CLR_bit(TCCR0,COM01);
		break;
		case OC0_TOGGLE:
		SET_bit(TCCR0,COM00);
		CLR_bit(TCCR0,COM01);
		break;
		case OC0_NON_INVERTING:
		CLR_bit(TCCR0,COM00);
		SET_bit(TCCR0,COM01);
		break;
		case OC0_INVERTING:
		SET_bit(TCCR0,COM00);
		SET_bit(TCCR0,COM01);
		break;
	}
}

void TIMER0_OV_InterruptEnable(void)
{
	SET_bit(TIMSK,TOIE0);
}
void TIMER0_OV_InterruptDisable(void)
{
	CLR_bit(TIMSK,TOIE0);
}
void TIMER0_OC_InterruptEnable(void)
{
	SET_bit(TIMSK,OCIE0);
}
void TIMER0_OC_InterruptDisable(void)
{
	CLR_bit(TIMSK,OCIE0);
}

/*************************************************************************/

void Timer1_Init( Timer1Mode_type mode,Timer1Scaler_type scaler)
{
	switch (mode)
	{
		case TIMER1_NORMAL_MODE:
		CLR_bit(TCCR1A,WGM10);
		CLR_bit(TCCR1A,WGM11);
		CLR_bit(TCCR1B,WGM12);
		CLR_bit(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_ICR_TOP_MODE:
		CLR_bit(TCCR1A,WGM10);
		CLR_bit(TCCR1A,WGM11);
		SET_bit(TCCR1B,WGM12);
		SET_bit(TCCR1B,WGM13);
		break;
		
		case TIMER1_CTC_OCRA_TOP_MODE:
		CLR_bit(TCCR1A,WGM10);
		CLR_bit(TCCR1A,WGM11);
		SET_bit(TCCR1B,WGM12);
		CLR_bit(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLR_bit(TCCR1A,WGM10);
		SET_bit(TCCR1A,WGM11);
		SET_bit(TCCR1B,WGM12);
		SET_bit(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_bit(TCCR1A,WGM10);
		SET_bit(TCCR1A,WGM11);
		SET_bit(TCCR1B,WGM12);
		SET_bit(TCCR1B,WGM13);
		break;
	}

	TCCR1B&=0XF8;
	TCCR1B|=scaler;

}
void Timer1_OCRA1Mode(OC1A_Mode_type oc1a_mode)
{
	switch (oc1a_mode)
	{
		case OCRA_DISCONNECTED:
		CLR_bit(TCCR1A,COM1A0);
		CLR_bit(TCCR1A,COM1A1);
		break;
		case OCRA_TOGGLE:
		SET_bit(TCCR1A,COM1A0);
		CLR_bit(TCCR1A,COM1A1);
		break;
		case OCRA_NON_INVERTING:
		CLR_bit(TCCR1A,COM1A0);
		SET_bit(TCCR1A,COM1A1);
		break;
		case OCRA_INVERTING:
		SET_bit(TCCR1A,COM1A0);
		SET_bit(TCCR1A,COM1A1);
		break;
	}
}
void Timer1_OCRB1Mode(OC1B_Mode_type oc1b_mode)
{
	switch (oc1b_mode)
	{
		case OCRB_DISCONNECTED:
		CLR_bit(TCCR1A,COM1B0);
		CLR_bit(TCCR1A,COM1B1);
		break;
		case OCRB_TOGGLE:
		SET_bit(TCCR1A,COM1B0);
		CLR_bit(TCCR1A,COM1B1);
		break;
		case OCRB_NON_INVERTING:
		CLR_bit(TCCR1A,COM1B0);
		SET_bit(TCCR1A,COM1B1);
		break;
		case OCRB_INVERTING:
		SET_bit(TCCR1A,COM1B0);
		SET_bit(TCCR1A,COM1B1);
		break;
	}
}
void Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
	SET_bit(TCCR1B,ICES1);
	
	else if(edge==FALLING)
	CLR_bit(TCCR1B,ICES1);

}
/****************************Timer 1 Interrupt functions**************************************/

void Timer1_ICU_InterruptEnable(void)
{
	SET_bit(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLR_bit(TIMSK,TICIE1);
}
void Timer1_OVF_InterruptEnable(void)
{
	SET_bit(TIMSK,TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLR_bit(TIMSK,TOIE1);
}
void Timer1_OCA_InterruptEnable(void)
{
	SET_bit(TIMSK,OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLR_bit(TIMSK,OCIE1A);
}
void Timer1_OCB_InterruptEnable(void)
{
	SET_bit(TIMSK,OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLR_bit(TIMSK,OCIE1B);
}