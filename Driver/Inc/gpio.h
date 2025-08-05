/*
 * gpio.h
 *
 *  Created on: Jul 31, 2025
 *      Author: Sujith S Babu
 */

#ifndef DRIVER_INC_GPIO_H_
#define DRIVER_INC_GPIO_H_
#include "peripheral_clock.h"

/* Function prototypes */
void gpioA_init(void);
void usart_init(void);
void usart_set_baudrate(USART_RegDef_Struct*);



#endif /* DRIVER_INC_GPIO_H_ */
