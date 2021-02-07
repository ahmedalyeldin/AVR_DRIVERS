/*
 * sensors.c
 *
 * Created: 10-12-2020 10:39:35
 *  Author: ahmed
 */ 
#include "sensors.h"

u16 Volt_Read(void)
{
	u16 adc = ADC_Read(POT_CH);
	u16 volt = ((u32)adc*5000)/1023;
	return volt;
}
u16 Temp_Read(void)
{
	u16 adc = ADC_Read(POT_CH);
	u16 volt = ((u32)adc*5000)/1024;
	u16 temp = volt;
	return temp;
}