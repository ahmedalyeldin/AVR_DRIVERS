/*
 * EX_Interupt.c
 *
 * Created: 13-12-2020 13:41:21
 *  Author: ahmed
 */ 
#include "EX_Interupt.h"
#include "LCD.h"
/****************************Pointer to functions to be assigned to ISR*********************************/


/************************************Enable/Disable functions***********************************/
void EXI_Enable(ExInterruptSource_type Interrupt)
{
	switch(Interrupt){
		case EX_INT0:
		SET_bit(GICR,INT0);
		break;
		case EX_INT1:
		SET_bit(GICR,INT1);
		break;
		case EX_INT2:
		SET_bit(GICR,INT2);
		break;
	}
}

void EXI_Disable(ExInterruptSource_type Interrupt)
{
	switch(Interrupt){
		case EX_INT0:
		CLR_bit(GICR,INT0);
		break;
		case EX_INT1:
		CLR_bit(GICR,INT1);
		break;
		case EX_INT2:
		CLR_bit(GICR,INT2);
		break;
	}
}
/************************************Control function*****************************/
void EXI_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge)
{
	switch(Interrupt){
		case EX_INT0:
		switch(Edge){		
			case LOW_LEVEL:
			CLR_bit(MCUCR,ISC00);
			CLR_bit(MCUCR,ISC01);
			break;
			case ANY_LOGIC_CHANGE:
			SET_bit(MCUCR,ISC00);
			CLR_bit(MCUCR,ISC01);
			break;
			case FALLING_EDGE:
			CLR_bit(MCUCR,ISC00);
			SET_bit(MCUCR,ISC01);
			break;
			case RISING_EDGE:
			SET_bit(MCUCR,ISC00);
			SET_bit(MCUCR,ISC01);
			break;
			
		}
		break;
		case EX_INT1:
		switch(Edge){
			case LOW_LEVEL:
			CLR_bit(MCUCR,ISC10);
			CLR_bit(MCUCR,ISC11);
			break;
			case ANY_LOGIC_CHANGE:
			SET_bit(MCUCR,ISC10);
			CLR_bit(MCUCR,ISC11);
			break;
			case FALLING_EDGE:
			CLR_bit(MCUCR,ISC10);
			SET_bit(MCUCR,ISC11);
			break;
			case RISING_EDGE:
			SET_bit(MCUCR,ISC10);
			SET_bit(MCUCR,ISC11);
			break;
			
		}
		break;
		case EX_INT2:
		switch(Edge){
			case FALLING_EDGE:
			CLR_bit(MCUCSR,ISC2);
			break;
			case RISING_EDGE:
			SET_bit(MCUCSR,ISC2);
			break;
			default:
			CLR_bit(MCUCSR,ISC2);
		}
		break;
	}
}