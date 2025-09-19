/*
 * LEDMAT_program.c
 *
 *  Created on: Aug 31, 2025
 *      Author: maria
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"MRCC_INTERFACE.h"
#include"MGPIO_Interface.h"
#include"MSYSTICK_interface.h"


void HLEDMAT_voidinit()
{
    // Rows PA0–PA7
    for (u8 pin = 0; pin < 8; pin++)
    {
        MGPIO_voidSetPinMode(PORTA, pin, OUTPUT);
        MGPIO_voidSetOutPutConfig(PORTA, pin, PUSH_PULL, LOW);
    }

    // Columns PA8–PA12
    for (u8 pin = 8; pin <= 12; pin++)
    {
        MGPIO_voidSetPinMode(PORTA, pin, OUTPUT);
        MGPIO_voidSetOutPutConfig(PORTA, pin, PUSH_PULL, LOW);
    }

    // Columns PB0–PB2
    for (u8 pin = 0; pin <= 2; pin++)
    {
        MGPIO_voidSetPinMode(PORTB, pin, OUTPUT);
        MGPIO_voidSetOutPutConfig(PORTB, pin, PUSH_PULL, LOW);
    }
}

static void HLEDMAT_voidsetrowvalue (u8 copy_u8row)
{
	/*set raw  values PA0->PA7 according to input*/
	for (u8 pin = 0; pin < 8; pin++)
	    {
	        u8 bitVal = (copy_u8row >> pin) & 0x01;
	        MGPIO_voidSetValue(PORTA, pin, bitVal);  // PA0..PA7
	    }
}

static void HLEDMAT_voiddeactivateallcoloumns()
{
    // Deactivate PA8..PA12
    for (u8 pin = 8; pin <= 12; pin++)
    {
        MGPIO_voidSetValue(PORTA, pin, PIN_HIGH);
    }

    // Deactivate PB0..PB2
    for (u8 pin = 0; pin <= 2; pin++)
    {
        MGPIO_voidSetValue(PORTB, pin, PIN_HIGH);
    }
}

void HLEDMAT_voiddisplay(u8* copy_pu8ptr)
{
    for (u8 col = 0; col < 8; col++)
    {
        // Step 1: Deactivate all columns
        HLEDMAT_voiddeactivateallcoloumns();

        // Step 2: Set row values
        HLEDMAT_voidsetrowvalue(copy_pu8ptr[col]);

        // Step 3: Activate current column
        if (col <= 4) {
            MGPIO_voidSetValue(PORTA, col + 8, PIN_LOW);   // PA8..PA12
        } else {
            MGPIO_voidSetValue(PORTB, col - 5, PIN_LOW);   // PB0..PB2
        }

        // Step 4: Small delay
        MSTK_voidDelayus(1000);

        // Step 5: Deactivate again before next col
        HLEDMAT_voiddeactivateallcoloumns();
    }
}


void ledmat_name()
{
	u8 Name_MARIAM[6][8] = {
			    {0, 126, 14, 24, 14, 126, 0, 0},   // M
				{0, 120, 28, 22, 28, 120, 0, 0},// A
			    {0, 0, 126, 26, 122, 78, 0, 0},// R
			    {0, 0, 66, 126, 126, 66, 0, 0},  // I
				{0, 120, 28, 22, 28, 120, 0, 0},// A
			    {0, 126, 14, 24, 14, 126, 0, 0}    // M
	    };

	// Build long message buffer (columns)
	    u8 fullMessage[50] = {0}; // 4 letters * 8 + spacing
	    u8 totalCols = 0;

	    for(u8 letter=0; letter<6; letter++)
	    {
	        for(u8 col=0; col<8; col++)
	        {
	            fullMessage[totalCols++] = Name_MARIAM[letter][col];
	        }
	        fullMessage[totalCols++] = 0x00; // 1 column spacing
	    }

	    u8 frame[8]; // temporary 8x8 display window



	    	// Slide window over fullMessage

	        for(u8 shift=0; shift <= totalCols-8; shift++)
	        {
	            for(u8 refresh=0; refresh<10; refresh++) // persistence
	            {
	                for(u8 col=0; col<8; col++)
	                {
	                    frame[col] = fullMessage[shift+col];
	                }
	                HLEDMAT_voiddisplay(frame);
	            }
	        }


}


