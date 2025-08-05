/*
 * memory_dump.c
 *
 *  Created on: Aug 5, 2025
 *      Author: Sujith S Babu
 */

#include "memory_dump.h"

/*Macros*/
#define  DUMP_START_ADDR_SRAM     0x20000000U

USART_RegDef_Struct* pUsart = USART2;


/*API to handle memory dump */
void get_memory_dump(int option)
{

	usart_send_string(pUsart, "\r\n");
    usart_send_string(pUsart, "*****************MEMORY DUMP*****************");
    usart_send_string(pUsart, "\r\n");
    if(option == 1)
    {
		usart_send_string(pUsart, "First 16 addresses of SRAM1:");
		usart_send_string(pUsart, "\r\n");
		for(uint8_t i = 0 ; i < 64; i +=4)//i=64,considering only first 16 addresses of SRAM1

		{
		   uint32_t* pMemdumpSRAM1 = (uint32_t*) (DUMP_START_ADDR_SRAM + i);


		   usart_send_hex(pUsart, (uint32_t)pMemdumpSRAM1);
		   usart_send_char(pUsart, ':');

		   usart_send_hex(pUsart, *pMemdumpSRAM1);
		   usart_send_string(pUsart, "\r\n");
	   }

    }
    else if(option == 2)
    {
    	usart_send_string(pUsart, "GPIOA Registers Memory Dump:");
    	usart_send_string(pUsart, "\r\n");
		for(uint8_t i = 0 ; i < 40; i +=4)//i==40,considering only GPIOA registers

		{
		   uint32_t* pMemdumpGPIOA = (uint32_t*) (GPIOA_BASEADDR + i);


		   usart_send_hex(pUsart, (uint32_t)pMemdumpGPIOA);
		   usart_send_char(pUsart, ':');

		   usart_send_hex(pUsart, *pMemdumpGPIOA);
		   usart_send_string(pUsart, "\r\n");
	   }
    }
    else if(option == 3)
	{
		usart_send_string(pUsart, "USART2 Registers Memory Dump:");
		usart_send_string(pUsart, "\r\n");
		for(uint8_t i = 0 ; i < 28; i +=4)//i=28,considering only USART2 registers

		{
		   uint32_t* pMemdumpUSART2 = (uint32_t*) (USART_2_BASEADDR + i);


		   usart_send_hex(pUsart, (uint32_t)pMemdumpUSART2);
		   usart_send_char(pUsart, ':');

		   usart_send_hex(pUsart, *pMemdumpUSART2);
		   usart_send_string(pUsart, "\r\n");
	   }
	}



}
