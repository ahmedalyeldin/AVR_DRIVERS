/*
 * ADC.h
 *
 * Created: 09-12-2020 10:25:02
 *  Author: ahmed
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"

typedef enum{
	ADC_PRESCALER_2 = 1,
	ADC_PRESCALER_4,
	ADC_PRESCALER_8,
	ADC_PRESCALER_16,
	ADC_PRESCALER_32,
	ADC_PRESCALER_64,
	ADC_PRESCALER_128
	}ADC_Vref_Type;

typedef enum{
	VREF_AREF,
	VREF_AVCC,
	VREF_256
}PRESCALER;

typedef enum{
	CH0 = 0,
	CH1,
	CH2,
	CH3,
	CH4,
	CH5,
	CH6,
	CH7,
}Channel;

void ADC_Init(ADC_Vref_Type vref,PRESCALER scaler);
u16 ADC_Read(Channel ch);



#endif /* ADC_H_ */