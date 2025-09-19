/*
 * MUART_interface.h
 *
 *  Created on: Sep 7, 2025
 *      Author: Mm
 */

#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_

void MUART_voidinit();

void MUART_voidsenddata(u8 copy_u8data);
u8 MUART_voidrecievedata();

void MUART_voidsendstring(u8 *copy_pu8str);
void MUART_voidrecievestring(u8 *copy_pu8str);

#endif /* MUART_INTERFACE_H_ */
