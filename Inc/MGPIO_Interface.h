/*
 * MGPIO_Interface.h
 *
 *  Created on: Aug 18, 2025
 *      Author: maria
 */

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

typedef enum{
	PORTA,
	PORTB,
	PORTC
}PORT_t;

typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}PIN_t;

typedef enum{
	INPUT,
	OUTPUT,
	ALTFUNC,
	ANALOG

}MODE_t;

typedef enum{
PUSH_PULL,
OPEN_DRAIN
}OUT_TYPE_t;

typedef enum{
	LOW,
	MEDIUM,
	HIGH,
	VERYHIGH
}SPEED_t;

typedef enum{
	PIN_LOW,
	PIN_HIGH
}VALUE_t;
typedef enum{
	PULL_UP,
	PULL_DOWN,
	FLOATING
}IN_TYPE_t;

typedef enum{
	AF0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15

}ALT_FUNC_t;

void MGPIO_voidSetPinMode( PORT_t copy_uddtport, PIN_t copy_uddtpin, MODE_t copy_uddtmode);

/*****************OUTPUTMODE*******************/
void MGPIO_voidSetOutPutConfig(PORT_t copy_uddtport, PIN_t copy_uddtpin, OUT_TYPE_t copy_uddtoutput, SPEED_t copy_uddtspeed);
void MGPIO_voidSetValue(PORT_t copy_uddtport, PIN_t copy_uddtpin, VALUE_t copy_uddtvalue);
void MGPIO_voidSetAtomicValue(PORT_t copy_uddtport, PIN_t copy_uddtpin, VALUE_t copy_uddtvalue);
void MGPIO_voidSetPortValue(PORT_t Copy_uddtPort,u16 Copy_u16Value);
/*****************INPUTMODE********************/
void MGPIO_voidSeINPutConfig(PORT_t copy_uddtport, PIN_t copy_uddtpin,IN_TYPE_t copy_udttinput);
VALUE_t MGPIO_u8GetPinValue(PORT_t copy_uddtport, PIN_t copy_uddtpin);

/******************ALTFUNCMODE******************/
void MGPIO_AltFuncConfig(PORT_t copy_uddtport, PIN_t copy_uddtpin, ALT_FUNC_t copy_uddtaltfunc);

#endif /* MGPIO_INTERFACE_H_ */
