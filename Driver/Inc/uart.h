/*
 * uart.h
 *
 *  Created on: Jul 31, 2025
 *      Author: Sujith S Babu
 */

#ifndef DRIVER_INC_UART_H_
#define DRIVER_INC_UART_H_

#include "stm32f407_xx_MemMap.h"
#include "debug_handler.h"

/* Function prototypes */
void usart_send_char(USART_RegDef_Struct*,char);
void usart_send_hex(USART_RegDef_Struct*, uint32_t);
void usart_send_string(USART_RegDef_Struct*,char*);
void enable_usart2_irq();
void USART2_IRQHandler(void);


#endif /* DRIVER_INC_UART_H_ */
