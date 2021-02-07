/*
 * KeyPad.h
 *
 * Created: 07-12-2020 09:57:01
 *  Author: ahmed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO_Interface.h"
#define FIRST_INPUT  PIND0
#define FIRST_OUTPUT PINC0
#define NO_KEY '.'

u8 KEYPAD_Getkey(void);



#endif /* KEYPAD_H_ */