/*
 * MEXTI_Interface.h
 *
 *  Created on: Aug 21, 2025
 *      Author: maria
 */

#ifndef MEXTI_INTERFACE_H_
#define MEXTI_INTERFACE_H_

typedef enum
{
	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15
}EXTI_LINE_t;

typedef enum
{
	EXTI_FALLING,
	EXTI_RISING,
	EXTI_ONCHANGE
}EXTI_TRIGGERMODE_t;

 typedef enum
 {
	 EXTI_PORTA,
	 EXTI_PORTB,
	 EXTI_PORTC
 }EXTI_PORT_t;

 void EXTI_voidSetInterruptPort(EXTI_LINE_t copy_uddtline, EXTI_PORT_t copy_uddtport);

void EXTI_voidEnable(EXTI_LINE_t copy_uddtline);
void EXTI_voidDisable(EXTI_LINE_t copy_uddtline);

void SetTrigger(EXTI_LINE_t copy_uddtline , EXTI_TRIGGERMODE_t copy_uddtmode);

void EXTI_voidCallBack1(void(*ptr)(void),u8 copy_u8extinum);





#endif /* MEXTI_INTERFACE_H_ */
