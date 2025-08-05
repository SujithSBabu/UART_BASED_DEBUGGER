/*
 * debug_handler.c
 *
 *  Created on: Aug 4, 2025
 *      Author: Sujith S Babu
 */
#include <stdbool.h>
#include "debug_handler.h"

/*Variable to control state machine*/
System_State current_state = SYSTEM_RUNNING;


/*API to handle the commands processed by USART2 interrupt handler*/
void debug_handler(USART_RegDef_Struct* pUSART2,char ch)
{
	if(ch == '#')
    {
		if(current_state != SYSTEM_HALTED)
		{

			current_state = SYSTEM_HALTED;
			usart_send_string(pUSART2, "\r\nSystem halted by user\r\n");
		}

	}
	else if(ch == '>')
	{
		if(current_state == SYSTEM_HALTED)
		{
			current_state = SYSTEM_RUNNING;
			usart_send_string(pUSART2, "\r\nSystem resumed\r\n\r\n");
		}

	}


}
