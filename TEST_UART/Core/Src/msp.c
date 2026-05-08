/*
 * msp.c
 *
 *  Created on: May 8, 2026
 *      Author: trung
 */


#include "stm32f4xx_hal.h"
#include "main.h"

/* Low-Level Hardware Initialization */

void HAL_MspInit(void)
{
    /* Mục 1: Set up the priority grouping */
    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

    /* Mục 2: Enable the required system exceptions */
    SCB->SHCSR |= 0x7 << 16;

    /* Mục 3: Configure the priority for the system exception */
    HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
    HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
    HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
}

/* UART2 MSP Initialization */

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    if(huart->Instance == USART2)
    {
        GPIO_InitTypeDef gpio_uart;

        /* Enable the clock for USART2 and GPIOA */
        __HAL_RCC_USART2_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();

        /* Configure PA2 as USART2_TX */
        gpio_uart.Pin = GPIO_PIN_2;
        gpio_uart.Mode = GPIO_MODE_AF_PP;
        gpio_uart.Pull = GPIO_PULLUP;
        gpio_uart.Speed = GPIO_SPEED_FREQ_LOW;
        gpio_uart.Alternate = GPIO_AF7_USART2;
        HAL_GPIO_Init(GPIOA, &gpio_uart);

        /* Configure PA3 as USART2_RX */
        gpio_uart.Pin = GPIO_PIN_3;
        HAL_GPIO_Init(GPIOA, &gpio_uart);

        /* Enable the IRQ and set up the priority */
        HAL_NVIC_EnableIRQ(USART2_IRQn);
        HAL_NVIC_SetPriority(USART2_IRQn, 15, 0);
    }
}

/* UART2 MSP Deinitialization */

void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{
    if(huart->Instance == USART2)
    {
        /* Disable the NVIC IRQ for USART2 */
        HAL_NVIC_DisableIRQ(USART2_IRQn);

        /* Reset USART2 */
        __HAL_RCC_USART2_FORCE_RESET();
        __HAL_RCC_USART2_RELEASE_RESET();

        /* Disable USART2 Clock */
        __HAL_RCC_USART2_CLK_DISABLE();

        /* Deinitialization GPIO pins */
        HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2 | GPIO_PIN_3);
    }
}
