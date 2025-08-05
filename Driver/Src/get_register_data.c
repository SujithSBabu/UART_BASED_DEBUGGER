/*
 * get_register_data.c
 *
 *  Created on: Aug 4, 2025
 *      Author: Sujith S Babu
 */
#include <stdint.h>
#include "get_register_data.h"

/*API to fetch MSP special purpose register data*/
uint32_t get_MSP_data()
{
	volatile uint32_t  result = 0;
	/*Inline assembly instruction to fetch main stack pointer register data*/
	__asm volatile ("MRS %0, MSP" : "=r" (result));
	return result;
}

/*API to fetch PSP special purpose register data*/
uint32_t get_PSP_data()
{
	volatile uint32_t  result = 0;
	/*Inline assembly instruction to fetch process stack pointer register data*/
	__asm volatile ("MRS %0, PSP" : "=r" (result));
	return result;

}

/*API to fetch CONTROL special purpose register data*/
uint32_t get_CONTROL_data()
{
	volatile uint32_t  result = 0;
	/*Inline assembly instruction to fetch control register data*/
	__asm volatile ("MRS %0, CONTROL" : "=r" (result));
	return result;
}
