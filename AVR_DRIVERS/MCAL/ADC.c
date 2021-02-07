/*
 * ADC.c
 *
 * Created: 09-12-2020 10:24:34
 *  Author: ahmed
 */ 
#include "ADC.h"

void ADC_Init(ADC_Vref_Type vref,PRESCALER scaler)
{   /**** scaler *****/  
	ADCSRA = ADCSRA&0xf8;
	ADCSRA = ADCSRA|scaler;
	
	/**** ref *****/
	switch(vref)
	{
	case VREF_AREF:
	CLR_bit(ADMUX,REFS0);
	CLR_bit(ADMUX,REFS1);
	break;
	
	case VREF_AVCC:
	SET_bit(ADMUX,REFS0);
	CLR_bit(ADMUX,REFS1);
	break;
	
	case VREF_256:
	SET_bit(ADMUX,REFS0);
	SET_bit(ADMUX,REFS1);
	break;
	}
	SET_bit(ADCSRA,ADEN);
}
u16 ADC_Read(Channel ch)
{
	//select ch
	ADMUX |= ch;
	//start conv.
	SET_bit(ADCSRA,ADSC);
	while(GET_bit(ADCSRA,ADSC));
	//ADC value
	return ADC;
	}