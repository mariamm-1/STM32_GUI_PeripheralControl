/*
 * MNVIC_private.h
 *
 *  Created on: Aug 20, 2025
 *      Author: maria
 */

#ifndef MNVIC_PRIVATE_H_
#define MNVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS (0xE000E100)

typedef struct
{
	u32 ISER[8];
	u32 RES0[24];
	u32 ICER[8];
	u32 RES1[24];
	u32 ISPR[8];
	u32 RES2[24];
	u32 ICPR[8];
	u32 RES3[24];
	u32 IAPR[8];
	u32 RES4[56];
	u32 IPR[240];
	u32 RES5[580];
	u32 STIR;

}MNVIC_t;

#define NVIC ((volatile MNVIC_t*)(NVIC_BASE_ADDRESS))


#define SCB_AIRCR (*(volatile u32*)(0xE000ED0C))
#define VECTKEY   0x05FA0000

#endif /* MNVIC_PRIVATE_H_ */
