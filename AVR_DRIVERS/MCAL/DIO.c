/*
 * DIO.c
 *
 * Created: 01-12-2020 11:32:26
 *  Author: ahmed
 */ 
#include "DIO_Interface.h"
extern const DIO_PinStatus_type  PinsStatusArray[TOTAL_PINS];
void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status)
{
	u8 pin_num = pin%8;
	DIO_Port_type port = pin/8;
	switch(status)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_bit(DDRA,pin_num);
			CLR_bit(PORTA,pin_num);
			break;
			case PB:
			SET_bit(DDRB,pin_num);
			CLR_bit(PORTB,pin_num);
			break;
			case PC:
			SET_bit(DDRC,pin_num);
			CLR_bit(PORTC,pin_num);
			break;
			case PD:
			SET_bit(DDRD,pin_num);
			CLR_bit(PORTD,pin_num);
			break;
		}break;
		case INFREE:
		switch(port)
		{
			case PA:
			CLR_bit(DDRA,pin_num);
			CLR_bit(PORTA,pin_num);
			break;
			case PB:
			CLR_bit(DDRB,pin_num);
			CLR_bit(PORTB,pin_num);
			break;
			case PC:
			CLR_bit(DDRC,pin_num);
			CLR_bit(PORTC,pin_num);
			break;
			case PD:
			CLR_bit(DDRD,pin_num);
			CLR_bit(PORTD,pin_num);
			break;
		}break;
		case INPLUP:
		switch(port)
		{
			case PA:
			CLR_bit(DDRA,pin_num);
			SET_bit(PORTA,pin_num);
			break;
			case PB:
			CLR_bit(DDRB,pin_num);
			SET_bit(PORTB,pin_num);
			break;
			case PC:
			CLR_bit(DDRC,pin_num);
			SET_bit(PORTC,pin_num);
			break;
			case PD:
			CLR_bit(DDRD,pin_num);
			SET_bit(PORTD,pin_num);
			break;
		}break;
	}
}


void DIO_WritePin(DIO_Pin_type pin,DIO_Voltage_type volt)
{
	u8 pin_num = pin%8;
	DIO_Port_type port = pin/8;
	switch(volt)
	{
		case HIGH:
		switch(port)
		{
			case PA:
			SET_bit(PORTA,pin_num);
			break;
			case PB:
			SET_bit(PORTB,pin_num);
			break;
			case PC:
			SET_bit(PORTC,pin_num);
			break;
			case PD:
			SET_bit(PORTD,pin_num);
			break;
		}break;
		case LOW:
		switch(port)
		{
			case PA:
			CLR_bit(PORTA,pin_num);
			break;
			case PB:
			CLR_bit(PORTB,pin_num);
			break;
			case PC:
			CLR_bit(PORTC,pin_num);
			break;
			case PD:
			CLR_bit(PORTD,pin_num);
			break;
		}break;
	}
}

DIO_Voltage_type DIO_ReadPin(DIO_Pin_type pin)
{
	u8 pin_num = pin%8;
	DIO_Port_type port = pin/8;
	DIO_Voltage_type volt = LOW;
	switch(port)
	{
		case PA:
		volt = GET_bit(PINA,pin_num);
		break;
		case PB:
		volt = GET_bit(PINB,pin_num);
		break;
		case PC:
		volt = GET_bit(PINC,pin_num);
		break;
		case PD:
		volt = GET_bit(PIND,pin_num);
		break;
	}
	return volt;
}






void DIO_TogglePin(DIO_Pin_type pin)
{
	u8 pin_num = pin%8;
	DIO_Port_type port = pin/8;
		switch(port)
		{
			case PA:
			TGL_bit(PORTA,pin_num);
			break;
			case PB:
			TGL_bit(PORTB,pin_num);
			break;
			case PC:
			TGL_bit(PORTC,pin_num);
			break;
			case PD:
			TGL_bit(PORTD,pin_num);
			break;
		}
	

}
void DIO_WritePort(DIO_Port_type port,u8 data)
{
		switch(port)
		{
			case PA:
			PORTA = data;
			break;
			case PB:
			PORTB = data;
			break;
			case PC:
			PORTC = data;
			break;
			case PD:
			PORTD = data;
			break;
		}
}
DIO_Voltage_type DIO_ReadPort(DIO_Port_type port)
{
	u8 num = 0;
	switch(port)
	{
		case PA:
		num = PINA;
		case PB:
		num = PINB;
		case PC:
		num = PINC;
		case PD:
		num = PIND;
	}
	 return num;
}


void DIO_Init(void)
{
	DIO_Pin_type i;
	for(i=PINA0;i<TOTAL_PINS;i++)
	{
		
		DIO_InitPin(i,PinsStatusArray[i]);
		
		
	}
}