/*
 * MGPIO_Program.c
 *
 *  Created on: Aug 18, 2025
 *      Author: maria
 */

#include "STD_Types.h"
#include "BIT_MATH.h"

#include"MGPIO_private.h"
#include"MGPIO_Interface.h"

void MGPIO_voidSetPinMode( PORT_t copy_uddtport, PIN_t copy_uddtpin, MODE_t copy_uddtmode)
{
	if(copy_uddtport==PORTA && (copy_uddtpin>=13))
	{
	}
	else if((copy_uddtport==PORTB)&&((copy_uddtpin==PIN3)||(copy_uddtpin==PIN4)||(copy_uddtpin==PIN5)))
	{
	}
	else
	{
		switch(copy_uddtport)
						{case PORTA:
							GPIOA->MODER &=~(GPIO_MASK<<copy_uddtpin*2);
							GPIOA->MODER |=(copy_uddtmode<<copy_uddtpin*2);
							break;
						case PORTB:
							GPIOB->MODER &=~(GPIO_MASK<<copy_uddtpin*2);
							GPIOB->MODER |=(copy_uddtmode<<copy_uddtpin*2);
							break;
						case PORTC:
							GPIOC->MODER &=~(GPIO_MASK<<copy_uddtpin*2);
							GPIOC->MODER |=(copy_uddtmode<<copy_uddtpin*2);
							break;
	}}}
MGPIO_voidSetOutPutConfig(PORT_t Copy_uddtPort,PIN_t Copy_uddtPin,OUT_TYPE_t Copy_uddtType,SPEED_t Copy_uddtSpeed)
{
	if(Copy_uddtPort==PORTA && (Copy_uddtPin>=13))
	{

	}
	else if(Copy_uddtPort==PORTB && (Copy_uddtPin==3 ||Copy_uddtPin==4 ||Copy_uddtPin==5))
	{

	}
	else
	{
		switch(Copy_uddtPort)
		{
			case PORTA:
			GPIOA->OTYPER&=~(1<<Copy_uddtPin);
			GPIOA->OTYPER|=(Copy_uddtType<<Copy_uddtPin);
			GPIOA->OSPEEDR&=~(GPIO_MASK<<(Copy_uddtPin*2));
			GPIOA->OSPEEDR|=(Copy_uddtSpeed<<(Copy_uddtPin*2));
			break;
			case PORTB:
			GPIOB->OTYPER&=~(1<<Copy_uddtPin);
			GPIOB->OTYPER|=(Copy_uddtType<<Copy_uddtPin);
			GPIOB->OSPEEDR&=~(GPIO_MASK<<(Copy_uddtPin*2));
			GPIOB->OSPEEDR|=(Copy_uddtSpeed<<(Copy_uddtPin*2));
			break;
			case PORTC:
			GPIOC->OTYPER&=~(1<<Copy_uddtPin);
			GPIOC->OTYPER|=(Copy_uddtType<<Copy_uddtPin);
			GPIOC->OSPEEDR&=~(GPIO_MASK<<(Copy_uddtPin*2));
			GPIOC->OSPEEDR|=(Copy_uddtSpeed<<(Copy_uddtPin*2));
			break;
		}
	}
}
void MGPIO_voidSetValue(PORT_t copy_uddtport, PIN_t copy_uddtpin, VALUE_t copy_uddtvalue)
{
	if(copy_uddtport==PORTA && (copy_uddtpin>=13))
		{
		}
		else if((copy_uddtport==PORTB)&&((copy_uddtpin==PIN3)||(copy_uddtpin==PIN4)||(copy_uddtpin==PIN5)))
		{
		}
	else
	{	switch(copy_uddtport)
		{	case PORTA:
			GPIOA->ODR&=~(1<<copy_uddtpin);
			GPIOA->ODR|=(copy_uddtvalue<<copy_uddtpin);
			break;
		case PORTB:
			GPIOB->ODR&=~(1<<copy_uddtpin);
			GPIOB->ODR|=(copy_uddtvalue<<copy_uddtpin);
			break;
		case PORTC:
			GPIOC->ODR&=~(1<<copy_uddtpin);
			GPIOC->ODR|=(copy_uddtvalue<<copy_uddtpin);
			break;
}}}
void MGPIO_voidSetAtomicValue(PORT_t copy_uddtport, PIN_t copy_uddtpin, VALUE_t copy_uddtvalue)
{
	if(copy_uddtport==PORTA && (copy_uddtpin>=13))
			{
			}
			else if((copy_uddtport==PORTB)&&((copy_uddtpin==PIN3)||(copy_uddtpin==PIN4)||(copy_uddtpin==PIN5)))
			{
			}
		else {
			if(copy_uddtvalue==PIN_LOW)
			{copy_uddtpin+=16;
		}
			switch(copy_uddtport)
			{	case PORTA:
						GPIOA->BSRR=(1<<copy_uddtpin);
						break;
					case PORTB:
						GPIOB->BSRR=(1<<copy_uddtpin);
						break;
					case PORTC:
						GPIOC->BSRR=(1<<copy_uddtpin);
						break;
					default:
						break;
		}}}
 MGPIO_voidSeINPutConfig(PORT_t copy_uddtport, PIN_t copy_uddtpin,IN_TYPE_t copy_udttinput)
{
	if(copy_uddtport==PORTA && (copy_uddtpin>=13))
		{
		}
		else if((copy_uddtport==PORTB)&&((copy_uddtpin==PIN3)||(copy_uddtpin==PIN4)||(copy_uddtpin==PIN5)))
		{
		}
		else
		{
			switch(copy_uddtport)
							{case PORTA:
								GPIOA->PUPDR &=~(GPIO_MASK<<copy_uddtpin*2);
								GPIOA->PUPDR |=(copy_udttinput<<copy_uddtpin*2);
								break;
							case PORTB:
								GPIOB->PUPDR &=~(GPIO_MASK<<copy_uddtpin*2);
								GPIOB->PUPDR |=(copy_udttinput<<copy_uddtpin*2);
								break;
							case PORTC:
								GPIOC->PUPDR &=~(GPIO_MASK<<copy_uddtpin*2);
								GPIOC->PUPDR |=(copy_udttinput<<copy_uddtpin*2);
								break;
		}}
}
VALUE_t MGPIO_u8GetPinValue(PORT_t copy_uddtport, PIN_t copy_uddtpin)
{ u8 local_u8Value;
if(copy_uddtport==PORTA && (copy_uddtpin>=13))
			{
			}
			else if((copy_uddtport==PORTB)&&((copy_uddtpin==PIN3)||(copy_uddtpin==PIN4)||(copy_uddtpin==PIN5)))
			{
			}
			else
			{
				switch(copy_uddtport)
								{case PORTA:
									local_u8Value=GET_BIT(GPIOA->IDR,copy_uddtpin);
									break;
								case PORTB:
									local_u8Value=GET_BIT(GPIOB->IDR,copy_uddtpin);
									break;
								case PORTC:
									local_u8Value=GET_BIT(GPIOC->IDR,copy_uddtpin);
									break;
			}}
return local_u8Value;
}

void MGPIO_AltFuncConfig(PORT_t copy_uddtport, PIN_t copy_uddtpin, ALT_FUNC_t copy_uddtaltfunc)
{
	if(copy_uddtport==PORTA && (copy_uddtpin==13 ||copy_uddtpin==14 ||copy_uddtpin==15))
	{

	}
	else if(copy_uddtport==PORTB && (copy_uddtpin==3 ||copy_uddtpin==4 ||copy_uddtpin==5))
	{

	}
	else
	{
		switch(copy_uddtport)
		{
			case PORTA:
			if(copy_uddtpin<8)
			{
				GPIOA->AFRL&=~(ALT_MASK<<(copy_uddtpin*4));
				GPIOA->AFRL|=(copy_uddtaltfunc<<(copy_uddtpin*4));
			}
			else if(copy_uddtpin<16)
			{
				copy_uddtpin-=8;
				GPIOA->AFRH&=~(ALT_MASK<<(copy_uddtpin*4));
				GPIOA->AFRH|=(copy_uddtaltfunc<<(copy_uddtpin*4));
			}
			break;
			case PORTB:
			if(copy_uddtpin<8)
			{
				GPIOB->AFRL&=~(ALT_MASK<<(copy_uddtpin*4));
				GPIOB->AFRL|=(copy_uddtaltfunc<<(copy_uddtpin*4));
			}
			else if(copy_uddtpin<16)
			{
				copy_uddtpin-=8;
				GPIOB->AFRH&=~(ALT_MASK<<(copy_uddtpin*4));
				GPIOB->AFRH|=(copy_uddtaltfunc<<(copy_uddtpin*4));
			}
			break;
			case PORTC:
			if(copy_uddtpin<8)
			{
				GPIOC->AFRL&=~(ALT_MASK<<(copy_uddtpin*4));
				GPIOC->AFRL|=(copy_uddtaltfunc<<(copy_uddtpin*4));
			}
			else if(copy_uddtpin<16)
			{
				copy_uddtpin-=8;
				GPIOC->AFRH&=~(ALT_MASK<<(copy_uddtpin*4));
				GPIOC->AFRH|=(copy_uddtaltfunc<<(copy_uddtpin*4));
			}
			break;
		}
	}
}
 void MGPIO_voidSetPortValue(PORT_t Copy_uddtPort,u16 Copy_u16Value)
 {
     switch (Copy_uddtPort)
     {
         case PORTA:
             GPIOA->ODR = Copy_u16Value;
             break;
         case PORTB:
             GPIOB->ODR = Copy_u16Value;
             break;
         case PORTC:
             GPIOC->ODR = Copy_u16Value;
             break;
         default:
             // invalid port, do nothing or error handler
             break;
     }
 }
