/*
 * MUART_private.h
 *
 *  Created on: Sep 7, 2025
 *      Author: Mm
 */

#ifndef MUART_PRIVATE_H_
#define MUART_PRIVATE_H_


#define USART1_BASE_ADDRESS ( 0x40011000)

typedef struct
{
	u32 SBK :1;
	u32 RWU:1;
	u32 RE:1;
	u32 TE:1;
	u32 IDLEIE:1;
	u32 RXNEIE:1;
	u32 TCIE:1;
	u32 TXEIE:1;
	u32 PEIE:1;
	u32 PS:1;
	u32 PCE:1;
	u32 WAKE:1;
	u32 M:1;
	u32 UE:1;
	u32 Reserved:1;
	u32 OVER8:1;
	u32 Reserved2:16;
}USART_CR1;

typedef struct
{
	u32 SR;
	u32 DR;
	u32 BRR;
	USART_CR1 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}UART_t;


#define USART1 ((volatile UART_t*)USART1_BASE_ADDRESS)

#define TXE 7
#define RXNE 5

#endif /* MUART_PRIVATE_H_ */
