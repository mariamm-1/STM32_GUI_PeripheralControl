/*
 * MEXTI_program.c
 *
 *  Created on: Aug 21, 2025
 *      Author: maria
 */


#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"MEXTI_private.h"
#include"MEXTI_Interface.h"

#define EXTI_LINES 16
static void (*EXTI_PTR[EXTI_LINES])(void)={0};

void EXTI_voidSetInterruptPort(EXTI_LINE_t copy_uddtline, EXTI_PORT_t copy_uddtport)
{
	SYSCFG->EXTICR[copy_uddtline/4] &=~ (MASK<<(4*(copy_uddtline%4)));
	SYSCFG->EXTICR[copy_uddtline/4] |= (copy_uddtport<<(4*(copy_uddtline%4)));
}

void EXTI_voidEnable(EXTI_LINE_t copy_uddtline)
{
	EXTI->IMR |=(1<<copy_uddtline);
}

void EXTI_voidDisable(EXTI_LINE_t copy_uddtline)
{
	EXTI->IMR &=~(1<<copy_uddtline);
}

void SetTrigger(EXTI_LINE_t Copy_uddtline, EXTI_TRIGGERMODE_t Copy_uddtmode)
{
    switch(Copy_uddtmode)
    {
        case EXTI_FALLING:
        EXTI->FTSR |=(1<<Copy_uddtline);
        EXTI->RTSR &= ~(1 << Copy_uddtline);
        break;
        case EXTI_RISING:
        EXTI->RTSR |=(1<<Copy_uddtline);
        EXTI->FTSR &= ~(1 << Copy_uddtline);
        break;
        case EXTI_ONCHANGE:
        EXTI->RTSR |= (1 << Copy_uddtline);
        EXTI->FTSR |= (1 << Copy_uddtline);
        break;
    }
}

void EXTI_voidCallBack1(void(*ptr)(void),u8 copy_u8extinum)
{
	if (ptr!=0 && copy_u8extinum<EXTI_LINES )
	{
		EXTI_PTR[copy_u8extinum]=ptr;
	}

}


/********************************* ISRs *********************************/

// EXTI line0
void EXTI0_IRQHandler(void)
{
    if (EXTI_PTR[0] != 0) { EXTI_PTR[0](); }
    EXTI->PR |= (1 << 0);   // clear pending flag
}

// EXTI line1
void EXTI1_IRQHandler(void)
{
    if (EXTI_PTR[1] != 0) { EXTI_PTR[1](); }
    EXTI->PR |= (1 << 1);
}

// EXTI line2
void EXTI2_IRQHandler(void)
{
    if (EXTI_PTR[2] != 0) { EXTI_PTR[2](); }
    EXTI->PR |= (1 << 2);
}

// EXTI line3
void EXTI3_IRQHandler(void)
{
    if (EXTI_PTR[3] != 0) { EXTI_PTR[3](); }
    EXTI->PR |= (1 << 3);
}

// EXTI line4
void EXTI4_IRQHandler(void)
{
    if (EXTI_PTR[4] != 0) { EXTI_PTR[4](); }
    EXTI->PR |= (1 << 4);
}

// EXTI lines 5 to 9 share one ISR
void EXTI9_5_IRQHandler(void)
{
    for (u8 line = 5; line <= 9; line++)
    {
        if (EXTI->PR & (1 << line))   // check pending
        {
            if (EXTI_PTR[line] != 0) { EXTI_PTR[line](); }
            EXTI->PR |= (1 << line);  // clear pending
        }
    }
}

// EXTI lines 10 to 15 share one ISR
void EXTI15_10_IRQHandler(void)
{
    for (u8 line = 10; line <= 15; line++)
    {
        if (EXTI->PR & (1 << line))
        {
            if (EXTI_PTR[line] != 0) { EXTI_PTR[line](); }
            EXTI->PR |= (1 << line);
        }
    }
}

