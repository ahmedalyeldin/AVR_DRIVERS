/*
 * Utils.h
 *
 * Created: 01-12-2020 11:19:23
 *  Author: ahmed
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define GET_bit(reg,bit)  ((reg>>bit)&1)
#define SET_bit(reg,bit)  (reg=((1<<bit)|reg))
#define CLR_bit(reg,bit)  (reg=((~(1<<bit))&reg))
#define TGL_bit(reg,bit)  (reg=((1<<bit)^reg))



#endif /* UTILS_H_ */