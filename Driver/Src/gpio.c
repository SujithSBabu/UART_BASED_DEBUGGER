/*
 * gpio.c
 *
 *  Created on: Jul 31, 2025
 *      Author: Sujith S Babu
 */
#include "stm32f407_xx_MemMap.h"
#include "gpio.h"
#include "uart.h"

/* API for initializing GPIOA peripheral for enabling USART2 based communication */
void gpioA_init()
{
	GPIOA_CLK_EN();

	GPIO_RegDef_Struct* pGPIOA = GPIOA;

	/*MODER*/
	pGPIOA->MODER &= ~((3U<<(2*2))|(3U<<(3*2))); //clearing PA2 and PA3.
	pGPIOA->MODER |=  ((2U<<(2*2))|(2U<<(3*2)));  // Setting PA2 and PA3 in Alternate Function mode.


	/*OSPEED*/
	pGPIOA->OSPEEDR &= ~(3U<<(2*2)); //clearing PA2.
	pGPIOA->OSPEEDR |= (2U<<(2*2)); //Setting PA2 with High Speed.

	/*PUPDR*/
	pGPIOA->PUPDR   &= ~(3U<<(3*2));//Clearing PA3.
	pGPIOA->PUPDR   |=  (1U<<(3*2));//Setting PA3(USART1_RX) with PULL-UP pin state.

	/*AFLR*/
	pGPIOA->AFR[0]  &= ~((15U<<(2*4))|(15U<<(3*4)));//clearing PA2 and PA3
	pGPIOA->AFR[0]  |=  ((7U<<(2*4))|(7U<<(3*4)));//Setting AFR for both PA2(USART1_TX) and PA3(USART1_RX)(It's an input; pull-up prevents floating when idle.)


	usart_init();
}


void usart_init()
{
	USART2_CLK_EN();

	enable_usart2_irq();//To Enable USART2 interrupt in NVIC_ISER1

	USART_RegDef_Struct* pUsart = USART2;

	/*Setting up CR1 register */

	pUsart->USART_CR1 &= ~(1U<<13);//clearing UE bit in CR1
	usart_set_baudrate(pUsart);


	pUsart->USART_CR1 &= ~(1U<<2);//clearing RE bit in CR1
	pUsart->USART_CR1 |=  (1U<<2);//setting up RE bit in CR1

	pUsart->USART_CR1 &= ~(1U<<3);//clearing TE bit in CR1
	pUsart->USART_CR1 |=  (1U<<3);//setting up TE bit in CR1

	pUsart->USART_CR1 &= ~(1U<<5);//clearing RXNEIE
	pUsart->USART_CR1 |=  (1U<<5);//setting RXNEIE bit in CR1

	pUsart->USART_CR1 |=  (1U<<13);//setting up UE bit in CR1



}

/*API to set the baud rate register for USART2 */
void usart_set_baudrate(USART_RegDef_Struct* pUsart2)
{
	uint32_t pclkx,usart_div,M_Part,F_Part;
	uint32_t temp_reg = 0;

	/*API call to fetch peripheral clock value*/
	pclkx = get_pclk_value();

	if(pUsart2->USART_CR1 & (1<<15))
	{
		usart_div = (25 * pclkx)/ (2 * 9600);  //floating point math is expensive in embedded systems,so multiplied by 100.
	}
	else
	{
		usart_div = (25 * pclkx)/ (4 * 9600); //floating point math is expensive in embedded systems,so multiplied by 100.
	}

	/* Calculate mantissa part */
	M_Part = usart_div/100;

	temp_reg |= M_Part << 4;

	/* Calculate fractional part */
	F_Part = usart_div - (M_Part * 100);

	/* Calculate the final fractional part */
	if(pUsart2->USART_CR1 & (1<< 15))
	{
		F_Part = (((F_Part * 8) + 50)/100) & (0x7);//adding 50 to get the correct nearest value
	}
	else
	{
		F_Part = (((F_Part * 16) + 50)/100) & (0x0F);//adding 50 to get the correct nearest value
	}
    temp_reg |= F_Part;

    /* set USART BRR register */
    pUsart2->USART_BRR = temp_reg;
}
