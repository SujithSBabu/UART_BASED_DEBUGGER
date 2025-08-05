/*
 * debug_handler.h
 *
 *  Created on: Aug 4, 2025
 *      Author: Sujith S Babu
 */

#ifndef INC_DEBUG_HANDLER_H_
#define INC_DEBUG_HANDLER_H_

#include "uart.h"

/* For state machine */
typedef enum
{
  SYSTEM_RUNNING,
  SYSTEM_HALTED
}System_State;

/*Function Prototypes*/
void debug_handler(USART_RegDef_Struct*,char);

#endif /* INC_DEBUG_HANDLER_H_ */
