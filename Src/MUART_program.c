/*
 * MUART_program.c
 *
 *  Created on: Sep 7, 2025
 *      Author: Mm
 */

#include"STD_Types.h"
#include"BIT_MATH.h"
#include"MUART_interface.h"
#include"MUART_private.h"

void MUART_voidinit()
{
	//Oversampling=16
	USART1->CR1.OVER8=0;

	//baudrate=9600
	USART1->BRR=(104<<4)|3;

	//Word length=8 bit
	USART1->CR1.M=0;

	//Disable parity
	USART1->CR1.PCE=0;

	//Enable transmitter
	USART1->CR1.TE=1;

	//Enable Receiver
	USART1->CR1.RE=1;

	//Enable UART
	USART1->CR1.UE=1;
}

void MUART_voidsenddata(u8 copy_u8data)
{
	while (((USART1->SR) & (1 << TXE)) == 0);   // TXE flag
	    USART1->DR = copy_u8data;

}
u8 MUART_voidrecievedata()
{
	while (((USART1->SR) & (1 << RXNE)) == 0);   // RXE flag
		return (u8)(USART1 -> DR);

}

void MUART_voidsendstring(u8 *copy_pu8str)
{
	u8 i = 0;
	    while(copy_pu8str[i] != '\0')
	    {
	        MUART_voidsenddata(copy_pu8str[i]);
	        i++;
	    }
}
void MUART_voidrecievestring(u8 *copy_pu8str)
{
	u8 i = 0;
	u8 receivedChar;

	do
	{
		receivedChar = MUART_voidrecievedata();
		copy_pu8str[i] = receivedChar;
		i++;
	} while(receivedChar != '\r'); // Stop receiving when "Enter" (carriage return) is received

	copy_pu8str[i] = '\0';  // Null terminate string
}
