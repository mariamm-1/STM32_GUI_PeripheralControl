/*
 * MNVIC_program.c
 *
 *  Created on: Aug 20, 2025
 *      Author: maria
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"MNVIC_Interface.h"
#include"MNVIC_private.h"

u8 Global_u32Value;


void MNVIC_voidEnable(IRQn_t copy_uddtIRQ)
{
	 NVIC->ISER[copy_uddtIRQ >> 5] = (1U << (copy_uddtIRQ & 0x1F));

}

void MNVIC_voidDisable(IRQn_t copy_uddtIRQ)
{
	 NVIC->ICER[copy_uddtIRQ >> 5] = (1U << (copy_uddtIRQ & 0x1F));
}

void MNVIC_voidSetPendingFlag(IRQn_t copy_uddtIRQ)
{
	  NVIC->ISPR[copy_uddtIRQ >> 5] = (1U << (copy_uddtIRQ & 0x1F));
}

void MNVIC_voidClearPendingFlag(IRQn_t copy_uddtIRQ)
{
	  NVIC->ICPR[copy_uddtIRQ >> 5] = (1U << (copy_uddtIRQ & 0x1F));
}

u8 MNVIC_voidReadingActiveStatus(IRQn_t copy_uddtIRQ)
{
        return ( (NVIC->IAPR[copy_uddtIRQ >> 5] >> (copy_uddtIRQ & 0x1F)) & 0x1 );
}

void MNVIC_voidSeTGroupPriority(NVIC_GROUP_t copy_uddtGroupMode)
{
	u32 Local_u32Value=0;
	Local_u32Value=VECTKEY|(copy_uddtGroupMode<<8);
	SCB_AIRCR=Local_u32Value;
}
void MNVIC_voidSetInterruptPriority(IRQn_t copy_uddtIRQ, u8 copy_u8Group, u8 copy_u8SubGroup)
{
	switch(Global_u32Value)
		{
			case Group16Sub0:
			NVIC->IPR[ copy_uddtIRQ]=(copy_u8Group<<4);
			break;
			case Group8Sub2:
			NVIC->IPR[ copy_uddtIRQ]=(copy_u8Group<<5)|(copy_u8SubGroup<<4);
			break;
			case Group4Sub4:
			NVIC->IPR[ copy_uddtIRQ]=(copy_u8Group<<6)|(copy_u8SubGroup<<4);
			break;
			case Group2Sub8:
			NVIC->IPR[copy_uddtIRQ]=(copy_u8Group<<7)|(copy_u8SubGroup<<4);
			break;
			case Group0Sub16:
			NVIC->IPR[ copy_uddtIRQ]=(copy_u8SubGroup<<4);
			break;
		}

}
