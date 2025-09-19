/*
 * SPI_program.c
 *
 *  Created on: Sep 3, 2025
 *      Author: maria
 */

#include"BIT_MATH.h"
#include"STD_Types.h"
#include"MSPI_interface.h"
#include"MSPI_private.h"
#include"MSPI_config.h"

void MSPI_MASTERinit()
{
	//HW or SW ssm/ssi
	SPI -> CR1 |= (1<<SSM);
	SPI -> CR1 |=(1<<SSI);

	//MasterMode
	SPI -> CR1 |= (1<<MSTR);

	//FullDuplex
	SPI -> CR1 &=~ (1<<BIDIMODE);

	//data (8bit-16bit)
	SPI -> CR1 &=~ (1<<DFF);

	//LSB or MSB
	SPI -> CR1 &=~ (1<<LSBFIRST);

	//CPOL & CPHA
	SPI -> CR1 |= (1<<CPOL);
	SPI -> CR1 &=~ (1<<CPHA);

	//clock
	//SPI -> CR1 &=~(CLK_MASK<<BR0);

	//enable
	SPI -> CR1 |= (1<<SPE);
}
void MSPI_SLAVEinit()
{
	//HW or SW ssm/ssi
	//SPI -> CR1 &=~ (1<<SSM);

	//MasterMode
	SPI -> CR1 &=~ (1<<MSTR);

	//FullDuplex
	SPI -> CR1 &=~ (1<<BIDIMODE);

	//data (8bit-16bit)
	SPI -> CR1 &=~ (1<<DFF);

	//LSB or MSB
	SPI -> CR1 &=~ (1<<LSBFIRST);

	//CPOL & CPHA
	SPI -> CR1 |= (1<<CPOL);
	SPI -> CR1 &=~ (1<<CPHA);

	//clock
	//SPI -> CR1 &=~(CLK_MASK<<BR0);

	//enable
	SPI -> CR1 |= (1<<SPE);
}

u16 MSPI_u16trancieve(u16 copy_u16data)
{
	while(!GET_BIT(SPI -> SR, TXE));
	SPI -> DR= copy_u16data;
	while(!GET_BIT(SPI -> SR, RXNE));
	return (u16)SPI -> DR;
}
