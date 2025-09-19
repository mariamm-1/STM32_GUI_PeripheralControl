/*
 * MGPIO_private.h
 *
 *  Created on: Aug 18, 2025
 *      Author: maria
 */

#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_

#define GPIOA_BASE_ADDRESS ( 0x40020000)
#define GPIOB_BASE_ADDRESS ( 0x40020400)
#define GPIOC_BASE_ADDRESS ( 0x40020800)

#define GPIOA ((volatile GPIO_t*)(GPIOA_BASE_ADDRESS))
#define GPIOB ((volatile GPIO_t*)(GPIOB_BASE_ADDRESS))
#define GPIOC ((volatile GPIO_t*)(GPIOC_BASE_ADDRESS))

typedef struct {
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDR;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}GPIO_t;

#define GPIO_MASK 3
#define ALT_MASK 15

#endif /* MGPIO_PRIVATE_H_ */
