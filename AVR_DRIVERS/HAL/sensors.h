/*
 * sensors.h
 *
 * Created: 10-12-2020 10:39:26
 *  Author: ahmed
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_
#include "ADC.h"

#define POT_CH CH0
#define TEMP_CH CH7

u16 Volt_Read(void);
u16 Temp_Read(void);




#endif /* SENSORS_H_ */