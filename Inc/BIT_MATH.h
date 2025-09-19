/*
 * BIT_MATH.h
 *
 *  Created on: Aug 18, 2025
 *      Author: mariam
 *      discribtion:
 *      notes:
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define TOGGLE_BIT(reg,bit)    reg^=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=~(1<<bit)
#define GET_BIT(reg,bit)    (reg>>bit)&1

/* todo
ROTR_BIT(reg)
ROTL_BIT(reg)
SWAP_NIP(reg)
ASS_BIT(reg, bit,val)
*/


#endif /* BIT_MATH_H_ */
