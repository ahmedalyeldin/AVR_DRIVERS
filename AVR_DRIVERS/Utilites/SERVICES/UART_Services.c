/*
 * UART_Services.c
 *
 * Created: 24-12-2020 13:11:07
 *  Author: ahmed
 */ 
#include "UART_Services.h"

void UART_Sendstring(u8* str)
{
	for(u8 i = 0 ; str[i] ; i++)
	{
		UART_Send(str[i]);
	}
}
void UART_Sendstringchecksum(u8* str)
{
	u8 i,lenght;
	u16 sum = 0;
	while(str[lenght])
	{
		sum += str[lenght];
		lenght++;
	}
	UART_Send(lenght);
	for(i = 0;i< lenght;i++)
	{
		UART_Send(str[i]);
	}
	UART_Send((u8)sum);
	UART_Send((u8)sum>>8);
}
void UART_Recievestringchecksum(u8* str)
{
	u8 i,lenght = UART_Recieve();
	u16 sum_calc = 0;
	for(i = 0;i < lenght;i++)
	{
		str[i]=UART_Recieve();
		sum_calc+=str[i];
	}
	
}