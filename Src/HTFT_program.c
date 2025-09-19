/*
 * HTFT_program.c
 *
 *  Created on: Sep 3, 2025
 *      Author: maria
 */
#include"STD_Types.h"
#include"BIT_MATH.h"

#include"MGPIO_Interface.h"
#include"MSYSTICK_interface.h"
#include"MSPI_interface.h"

#include "HTFT_interface.h"
#include"HTFT_private.h"
#include"HTFT_config.h"




static void HTFT_voidwritedata(u8 copy_u8data)
{
	MGPIO_voidSetAtomicValue(TFT_PORT, CTRL_PIN, PIN_HIGH);
	(void) MSPI_u16trancieve(copy_u8data);
}
static void HTFT_voidwritecommand(u8 copy_u8CMD)
{
	MGPIO_voidSetAtomicValue(TFT_PORT, CTRL_PIN, PIN_LOW);
	(void) MSPI_u16trancieve(copy_u8CMD);
}

void HTFT_voidinit()
{
    // CONFIGURE CTRL AND RST  PINS
    MGPIO_voidSetPinMode(TFT_PORT, CTRL_PIN, OUTPUT);
    MGPIO_voidSetOutPutConfig(TFT_PORT, CTRL_PIN, PUSH_PULL, LOW);
    MGPIO_voidSetPinMode(TFT_PORT, RST_PIN, OUTPUT);
    MGPIO_voidSetOutPutConfig(TFT_PORT, RST_PIN, PUSH_PULL, LOW);

    // RESET  SEQUENCE
    MGPIO_voidSetAtomicValue(TFT_PORT, RST_PIN, PIN_HIGH);
    MSTK_voidDelayms(100);
    MGPIO_voidSetAtomicValue(TFT_PORT, RST_PIN, PIN_LOW);
    MSTK_voidDelayms(1);
    MGPIO_voidSetAtomicValue(TFT_PORT, RST_PIN, PIN_HIGH);
    MSTK_voidDelayms(100);
    MGPIO_voidSetAtomicValue(TFT_PORT, RST_PIN, PIN_LOW);
    MSTK_voidDelayms(100);
    MGPIO_voidSetAtomicValue(TFT_PORT, RST_PIN, PIN_HIGH);
    MSTK_voidDelayms(120);

    // SLEEP OUT
    HTFT_voidwritecommand(SLEEP_OUT);
    MSTK_voidDelayms(10);

    // SELECT COLOR MODE
    HTFT_voidwritecommand(COLOR_MODE);
    HTFT_voidwritedata(RGB565);

    // DISPLAY ON
    HTFT_voidwritecommand(DISPLAY_ON);

}


void HTFT_voiddisplay(const u16*copy_pu16PTR)
{
	u16 Local_u16iterator;
	u8 Local_u8highpart,Local_u8lowpart;

	//SET X
	HTFT_voidwritecommand(X_DIRECTION);
	HTFT_voidwritedata(START_X_B0);
	HTFT_voidwritedata(START_X_B1);
	HTFT_voidwritedata(END_X_B0);
	HTFT_voidwritedata(END_Y_B1);

	///SET Y
	HTFT_voidwritecommand(Y_DIRECTION);
	HTFT_voidwritedata(START_Y_B0);
	HTFT_voidwritedata(START_Y_B1);
	HTFT_voidwritedata(END_Y_B0);
	HTFT_voidwritedata(END_Y_B1);

	//WRITE ON SCREEN
	HTFT_voidwritecommand(SCREEN_WRITE);
	for (Local_u16iterator=0 ; Local_u16iterator<IMAGE_SIZE ; Local_u16iterator++)
	{
		Local_u8lowpart=(u8)copy_pu16PTR[Local_u16iterator];  //LSB
		Local_u8highpart=(u8)(copy_pu16PTR[Local_u16iterator]>>8);  //MSB

		HTFT_voidwritedata(Local_u8highpart);
		HTFT_voidwritedata(Local_u8lowpart);

	}

}
void HTFT_voidfillColor(u16 color)
{
    // Set column range (0 -> 127 for 128px width)
    HTFT_voidwritecommand(0x2A);
    HTFT_voidwritedata(0x00);
    HTFT_voidwritedata(0);
    HTFT_voidwritedata(0x00);
    HTFT_voidwritedata(127);

    // Set row range (0 -> 159 for 160px height)
    HTFT_voidwritecommand(0x2B);
    HTFT_voidwritedata(0x00);
    HTFT_voidwritedata(0);
    HTFT_voidwritedata(0x00);
    HTFT_voidwritedata(159);

    // Memory write
    HTFT_voidwritecommand(0x2C);

    // Send pixel data
    for (u16 i = 0; i < 128 * 160; i++)
    {
        HTFT_voidwritedata(color >> 8);
        HTFT_voidwritedata(color & 0xFF);
    }
}

