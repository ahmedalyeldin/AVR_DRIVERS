/*
 * UART_Services.h
 *
 * Created: 24-12-2020 13:10:54
 *  Author: ahmed
 */ 


#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_
#include "Utils.h"
#include "MemMap.h"
#include "DIO_Interface.h"
#include "UART.h"

void UART_Sendstring(u8* str);
void UART_Sendstringchecksum(u8* str);
void UART_Recievestringchecksum(u8* str);


#endif /* UART_SERVICES_H_ */