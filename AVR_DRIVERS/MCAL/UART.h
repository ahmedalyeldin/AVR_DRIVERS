/*
 * UART.h
 *
 * Created: 24-12-2020 11:30:08
 *  Author: ahmed
 */ 


#ifndef UART_H_
#define UART_H_
#include "DIO_Interface.h"
#include "Utils.h"
#include "MemMap.h"

void UART_Init(void);
void UART_Send(u8 data);
void UART_SendNumber(u32 num);
u8 UART_Recieve(void);
void UART_Recieve_Periodic(u8*pdata);


#endif /* UART_H_ */