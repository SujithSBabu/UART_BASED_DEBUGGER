/*
 * uart.c
 *
 *  Created on: Jul 31, 2025
 *      Author: Sujith S Babu
 */
#include "stm32f407_xx_MemMap.h"
#include "uart.h"

/*API to handle transmission of a character*/
void usart_send_char(USART_RegDef_Struct* pUSART,char ch)
{
	/* wait until TXE flag is set */
	while(!(pUSART->USART_SR & (1 << 7)));
	pUSART->USART_DR = ch;
	/* wait until whole transmission completes */
	while(!(pUSART->USART_SR & (1 << 6)));
}

/*API to handle transmission of a string*/
void usart_send_string(USART_RegDef_Struct* pUsart,char* pStr)
{
	while(*pStr)
	{
		usart_send_char(pUsart,*(pStr++));
	}
}

/*API to handle transmission of a hex value*/
void usart_send_hex(USART_RegDef_Struct* pUSARTx, uint32_t hex_value)
{
	char hex_char = '0' ;
	usart_send_string(pUSARTx, "0x");
	for(int8_t i = 28; i >= 0; i-=4)
	{
		uint8_t nibble = (hex_value >> i) & 0xF;
		if(nibble < 10)
		{
		  hex_char = '0' + nibble;
		}
		else if(nibble > 10)
		{
			hex_char = 'A' + (nibble - 10);
		}

		usart_send_char(pUSARTx, hex_char);
	}
}

/*API to enable USART2 interrupt*/
void enable_usart2_irq()
{
    NVIC_ISER1 = (1 << (38-32)); //Enable USART2 interrupt (Irq 38)
}

/*USART2 IRQ handler*/
void USART2_IRQHandler(void)
{
    USART_RegDef_Struct* pusart2 = USART2;
	while(!(pusart2->USART_SR & (1 << 5)));//Wait until RXE flag is set
	char ch = pusart2->USART_DR;

	/*Debug handler function call*/
	debug_handler(pusart2,ch);

}
