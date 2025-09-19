/*
 * MEXTI_private.h
 *
 *  Created on: Aug 21, 2025
 *      Author: maria
 */

#ifndef MEXTI_PRIVATE_H_
#define MEXTI_PRIVATE_H_


#define EXTI_BASE_ADDRESS (0x40013C00)
#define SYSCFG_BASE_ADDRESS (0x40013800)


typedef struct
{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;

}EXTI_t;

typedef struct
{
	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];
	u32 RES[2];
	u32 CMPCR;
}SYSCFG_t;

#define MASK 15


#define EXTI ((volatile EXTI_t*) EXTI_BASE_ADDRESS)
#define SYSCFG ((volatile SYSCFG_t*) SYSCFG_BASE_ADDRESS)

#endif /* MEXTI_PRIVATE_H_ */
