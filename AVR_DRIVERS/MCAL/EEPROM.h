/*
 * EEPROM.h
 *
 * Created: 22-12-2020 23:43:03
 *  Author: ahmed
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include "MemMap.h"
#include "DIO_Interface.h"

void EEPROM_write(u16 Address, u8 Data);
u8 EEPROM_read(u16 Address);





#endif /* EEPROM_H_ */