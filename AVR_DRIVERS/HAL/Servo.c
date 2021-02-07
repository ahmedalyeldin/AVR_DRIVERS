/*
 * Servo.c
 *
 * Created: 19-12-2020 22:24:34
 *  Author: ahmed
 */ 
#include "Servo.h"

void Servo_Writeangle(u8 angle)
{
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	ICR1 = 20000;
	OCR1A = (angle*5.55)+1000;
}