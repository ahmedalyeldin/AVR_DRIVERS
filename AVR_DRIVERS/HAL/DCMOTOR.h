/*
 * DCMOTOR.h
 *
 * Created: 02-12-2020 13:39:03
 *  Author: ahmed
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "DIO_Interface.h"
#include "Timers.h"

typedef enum{
	MOTOR1,
	MOTOR2
	}Motor_type;

void Motor_CCW(void);
void Motor_CW(void);
void Motor_stop(void);
void Motor_CW_Speed_Control(u8 speed);


#endif /* DCMOTOR_H_ */