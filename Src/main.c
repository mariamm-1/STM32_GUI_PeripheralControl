/*
 * main.c
 *
 *  Created on: Sep 8, 2025
 *      Author: Hardware Kit
 */

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "MRCC_interface.h"
#include "MGPIO_Interface.h"
#include "MUART_interface.h"
#include "MSYSTICK_interface.h"
#include "HTFT_interface.h"
#include"LEDMAT_interface.h"
#include"MUART_private.h"
#include"IMAGE.h"

#include <string.h>

#define CMD_SIZE 20
#define MAX_LEVEL 8

void MGPIO_void_TogglePin(PORT_t port, PIN_t pin)
{
    u8 current = MGPIO_u8GetPinValue(port, pin);
    if (current == HIGH){
    	MGPIO_voidSetValue(port, pin, PIN_LOW);
    }

    else{
    	MGPIO_voidSetValue(port, pin, PIN_HIGH);
    }

}
int main(void)
{
	u8 command[CMD_SIZE];
	u8 levels[8] = {1,3,5,7,4,6,2,8};

	// ---- Initialize RCC ----
	MRCC_voidInit();

	// Enable GPIOA, GPIOB, GPIOC, USART1, SPI1
	MRCC_voidEnablePeipheralClock(AHB1_BUS, AHB1_GPIOA);   // GPIOA
	MRCC_voidEnablePeipheralClock(AHB1_BUS, AHB1_GPIOB);   // GPIOB
	MRCC_voidEnablePeipheralClock(AHB1_BUS, AHB1_GPIOC);   // GPIOC
	MRCC_voidEnablePeipheralClock(APB2_BUS, APB2_USART1);   // USART1
	MRCC_voidEnablePeipheralClock(APB2_BUS, APB2_SPI1);  // SPI1

	MGPIO_voidSetPinMode(PORTB, PIN6, ALTFUNC);
	MGPIO_AltFuncConfig(PORTB, PIN6, AF7);
	MGPIO_voidSetPinMode(PORTB, PIN7, ALTFUNC);
	MGPIO_AltFuncConfig(PORTB, PIN7, AF7);

	MGPIO_voidSetPinMode(PORTA, PIN4, ALTFUNC);
	MGPIO_AltFuncConfig(PORTA, PIN4, AF5);

	MGPIO_voidSetPinMode(PORTA, PIN5, ALTFUNC);
	MGPIO_AltFuncConfig(PORTA, PIN5, AF5);

	MGPIO_voidSetPinMode(PORTA, PIN6, ALTFUNC);
	MGPIO_AltFuncConfig(PORTA, PIN6, AF5);

	MGPIO_voidSetPinMode(PORTA, PIN7, ALTFUNC);
	MGPIO_AltFuncConfig(PORTA, PIN7, AF5);

	// ---- GPIO Config ----
	// LED matrix -> PB0


	// Sound -> PC0
	MGPIO_voidSetPinMode(PORTC, PIN13, OUTPUT);
	MGPIO_voidSetOutPutConfig(PORTC, PIN13, PUSH_PULL, LOW);

	// ---- Init SysTick ----
	MSPI_MASTERinit();
	MSTK_voidInit();

	// TFT uses PA0 (RST), PA1 (DC), PA5 (SCK), PA7 (MOSI)


	// ---- Init UART ----
	MUART_voidinit();
	HTFT_voidinit();
	HTFT_voidfillColor(0x0000);


	while (1)
	{
		u8 cmd = MUART_voidrecievedata();

		switch(cmd)
		{
		case 'I':

			HTFT_voiddisplay(image_ARR);
			MUART_voidsendstring((u8 *)"IMG OK\n");
			break;

		case 'L':
			HLEDMAT_voidinit();
			ledmat_name();

			MUART_voidsendstring((u8 *)"LED OK\n");
			break;

		case 'O':// Play → LED ON
		    MGPIO_voidSetValue(PORTC, PIN13, PIN_HIGH);
		    MUART_voidsendstring((u8*)"LED ON (PLAY)\n");
		    break;
	    case 'T': // Pause → LED TOGGLE

	    	MGPIO_voidSetValue(PORTC, PIN13, PIN_LOW);
	    	MSTK_voidDelayms(200);
	    	MGPIO_voidSetValue(PORTC, PIN13, PIN_HIGH);
	    	MSTK_voidDelayms(200);
	    	MGPIO_voidSetValue(PORTC, PIN13, PIN_LOW);
	    	MSTK_voidDelayms(200);
	    	MGPIO_voidSetValue(PORTC, PIN13, PIN_HIGH);
	    	MSTK_voidDelayms(200);

		    break;
		 case 'S': // Stop → LED OFF
			 MGPIO_voidSetValue(PORTC, PIN13, PIN_LOW);
		   MUART_voidsendstring((u8*)"LED OFF (STOP)\n");
		    		break;


		}
	}

}

