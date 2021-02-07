/*
 * EEPROM.c
 *
 * Created: 22-12-2020 23:42:49
 *  Author: ahmed
 */ 
#include "EEPROM.h"
void EEPROM_write(u16 Address, u8 Data)
{
	
	while(EECR & (1<<EEWE));
	EEAR = Address;
	EEDR = Data;
	EECR |= (1<<EEMWE);
	EECR |= (1<<EEWE);
}
u8 EEPROM_read(u16 Address)
{
	while(EECR & (1<<EEWE));
	EEAR = Address;
	EECR |= (1<<EERE);
	return EEDR;
}