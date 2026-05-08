/*
 * main.c
 *
 *  Created on: May 8, 2026
 *      Author: trung
 */

#include "stm32f4xx_hal.h"
#include "main.h"
#include "string.h"

/* UART Handle Definition */
UART_HandleTypeDef huart2;

/* Data to transmit */
char *user_data = "The application is running\r\n";

/* Main Function */
int main(void)
{
    /* Step 1: Initialize HAL */
    HAL_Init();

    /* Step 2: Configure system clock */
    SystemClockConfig();

    /* Step 3: Initialize UART2 */
    UART2_Init();

    /* Step 4: Calculate data length */
    uint16_t len_of_data = strlen(user_data);

    /* Step 5: Transmit data via UART */
    if (HAL_UART_Transmit(&huart2, (uint8_t*)user_data, len_of_data, HAL_MAX_DELAY) != HAL_OK)
    {
        Error_handler();
    }

    /* Step 6: Infinite loop */
    while(1)
    {
        /* Optional: Add more code here */
    }

    return 0;
}

/* UART2 Initialization Function */
void UART2_Init(void)
{
    /* Step 1: Link the handle to the peripheral instance */
    huart2.Instance = USART2;

    /* Step 2: Configure UART parameters */
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;

    /* Step 3: Call the initialization API */
    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
        Error_handler();
    }
}

/* System Clock Configuration */
void SystemClockConfig(void)
{
    /* This function initializes the system clock */
}

/* Error Handler */
void Error_handler(void)
{
    while(1)
    {
        /* The program will be stuck here if an error occurs */
    }
}
