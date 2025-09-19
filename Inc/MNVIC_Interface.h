/*
 * MNVIC_Interface.h
 *
 *  Created on: Aug 20, 2025
 *      Author: maria
 */

#ifndef MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_

typedef enum{
	 NMI   			  = -14,
	 HardFault        = -13,
	 MemoryManagement = -12,
	 BusFault         = -11,
	 UsageFault       = -10,
	 SVCall_IRQ       = -5,
	 DebugMonitor     = -4,
	 PendSV_IRQn      = -2,
	 SysTick_IRQn     = -1,
	 WWDG 		= 0	,
	 PVD 		= 1	,
	 TAMP_STAMP	= 2	,
	 RTC_WKUP	= 3	,
	 FLASH		= 4	,
	 RCC			= 5	,
	 EXTI0		= 6	,
	 EXTI1		= 7	,
	 EXTI2		= 8	,
	 EXTI3		= 9 ,
	 EXTI4		= 10,
	 DMA1_Stream0= 11,
	 DMA1_Stream1= 12,
	 DMA1_Stream2= 13,
	 DMA1_Stream3= 14,
	 DMA1_Stream4= 15,
	 DMA1_Stream5= 16,
	 DMA1_Stream6= 17,
	 ADC			= 18,
	 EXTI9_5		= 23,
	 TIM1_BRK_TIM9=24,
	 TIM1_UP_TIM10=25,
	 TIM1_TRG_COM_TIM11 = 26,
	 TIM1_CC		= 27,
	 TIM2		= 28,
	 TIM3		= 29,
	 TIM4		= 30,
	 I2C1_EV		= 31,
	 I2C1_ER		= 32,
	 I2C2_EV		= 33,
	 I2C2_ER		= 34,
	 SPI1		= 35,
	 SPI2		= 36,
	 USART1		= 37,
	 USART2		= 38,
	 EXTI15_10	= 40,
	 RTC_Alarm	= 41,
	 OTG_FS_WKUP	= 42,
	 DMA1_Stream7= 47,
	 SDIO		= 49,
	 TIM5		= 50,
	 SPI3		= 51,
	 DMA2_Stream0= 56,
	 DMA2_Stream1= 57,
	 DMA2_Stream2= 58,
	 DMA2_Stream3= 59,
	 DMA2_Stream4= 60,
	 OTG_FS		= 67,
	 DMA2_Stream5= 68,
	 DMA2_Stream6= 69,
	 DMA2_Stream7= 70,
	 USART6		= 71,
	 I2C3_EV		= 72,
	 I2C3_ER		= 73,
	 FPU			= 81,
	 SPI4		= 84
}IRQn_t;

typedef enum
{
	Group16Sub0=3,
	Group8Sub2,
	Group4Sub4,
	Group2Sub8,
	Group0Sub16
}NVIC_GROUP_t;

void MNVIC_voidEnable(IRQn_t copy_uddtIRQ);
void MNVIC_voidDisable(IRQn_t copy_uddtIRQ);
void MNVIC_voidSetPendingFlag(IRQn_t copy_uddtIRQ);
void MNVIC_voidClearPendingFlag(IRQn_t copy_uddtIRQ);
u8 MNVIC_voidReadingActiveStatus(IRQn_t copy_uddtIRQ);
void MNVIC_voidSeTGroupPriority(NVIC_GROUP_t copy_uddtGroupMode);
void MNVIC_voidSetInterruptPriority(IRQn_t copy_uddtIRQ, u8 copy_u8Groub, u8 copy_u8SubGroub);


#endif /* MNVIC_INTERFACE_H_ */
