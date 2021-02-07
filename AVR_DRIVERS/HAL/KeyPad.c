/*
 * KeyPad.c
 *
 * Created: 07-12-2020 09:57:11
 *  Author: ahmed
 */ 
#include "KeyPad.h"
#include "DIO_Interface.h"
static const u8 key[4][4] = {   {'7','8','9','/'},
	                            {'4','5','6','*'},
	                            {'1','2','3','-'},
				                {'c','0','=','+'}
                                                    };
									 
u8 KEYPAD_Getkey(void)
{
	u8 r,c,key1= NO_KEY;
	DIO_WritePin(FIRST_OUTPUT+0,HIGH);
	DIO_WritePin(FIRST_OUTPUT+1,HIGH);
	DIO_WritePin(FIRST_OUTPUT+2,HIGH);
	DIO_WritePin(FIRST_OUTPUT+3,HIGH);
	for(r=0 ; r<4 ; r++)
	{
		DIO_WritePin(FIRST_OUTPUT+r,LOW);
		for(c=0 ; c<4 ; c++)
		{
			if(!DIO_ReadPin(FIRST_INPUT+c))
			{
				key1 = key[r][c];
				while(!DIO_ReadPin(FIRST_INPUT+c));
				
			}
		}
		DIO_WritePin(FIRST_OUTPUT+r,HIGH);
	}
	return key1;
}