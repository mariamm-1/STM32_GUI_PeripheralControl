/*
 * MSPI1_interface.h
 *
 *  Created on: Sep 3, 2025
 *      Author: maria
 */

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

void MSPI_MASTERinit();
void MSPI_SLAVEinit();

u16 MSPI_u16trancieve(u16 copy_u16data);


#endif /* MSPI_INTERFACE_H_ */
