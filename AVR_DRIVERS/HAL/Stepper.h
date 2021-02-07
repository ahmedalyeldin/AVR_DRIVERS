/*
 * Stepper.h
 *
 * Created: 08-12-2020 10:59:44
 *  Author: WENUS
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_

#include "DIO_interface.h"

#define COIL1_A PINC0
#define COIL1_B PINC1
#define COIL2_A PINC2
#define COIL2_B PINC3
#define DELAY1 10
#define DELAY 100
void STEPPER_BiPoler_CW(void);
void STEPPER_BiPoler_CCW(void);
void STEPPER_UnPoler_CW(void);
void STEPPER_UnPoler_CCW(void);
void STEPPER_RotatByAngel_UnPoler_CW(u16 degre);
void STEPPER_RotatByCycel_UnPoler_CW(u16 cycel);
void STEPPER_RotatByAngel_UnPoler_CCW(u16 degre);
void STEPPER_RotatByCycel_UnPoler_CCW(u16 cycel);
#endif /* STEPPER_H_ */