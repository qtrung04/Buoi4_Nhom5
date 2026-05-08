/*
 * it.c
 *
 *  Created on: May 8, 2026
 *      Author: trung
 */


#include "stm32f4xx_hal.h"
#include "main.h"

/* External UART Handle */
extern UART_HandleTypeDef huart2;

/* Interrupt Handlers */

void USART2_IRQHandler(void)
{
    HAL_UART_IRQHandler(&huart2);
}

void SysTick_Handler(void)
{
    HAL_IncTick();
    HAL_SYSTICK_IRQHandler();
}
