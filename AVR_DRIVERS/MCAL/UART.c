/*
 * UART.c
 *
 * Created: 24-12-2020 11:29:57
 *  Author: ahmed
 */ 
#include "UART.h"
void UART_Init(void)
{
	UBRRL = 51; //baudrate 9600 for 8MHz
	CLR_bit(UCSRA,U2X);
	SET_bit(UCSRB,TXEN);
	SET_bit(UCSRB,RXEN);
}
void UART_Send(u8 data)
{
	while(!GET_bit(UCSRA,UDRE));
	UDR = data;
}
u8 UART_Recieve(void)
{
	while(!GET_bit(UCSRA,RXC));
	return UDR;
}
void UART_Recieve_Periodic(u8*pdata)
{
	if(!GET_bit(UCSRA,RXC))
	{
		*pdata = UDR;
	}
}
void UART_SendNumber(u32 num)
{
	UART_Send((u8)num);
	UART_Send((u8)(num>>8));
	UART_Send((u8)(num>>16));
	UART_Send((u8)(num>>24));
}
