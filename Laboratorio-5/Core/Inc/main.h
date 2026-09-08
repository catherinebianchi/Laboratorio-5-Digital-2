/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define verde_Pin GPIO_PIN_1
#define verde_GPIO_Port GPIOC
#define boton1_Pin GPIO_PIN_0
#define boton1_GPIO_Port GPIOA
#define boton1_EXTI_IRQn EXTI0_IRQn
#define boton2_Pin GPIO_PIN_1
#define boton2_GPIO_Port GPIOA
#define boton2_EXTI_IRQn EXTI1_IRQn
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define rojo_Pin GPIO_PIN_4
#define rojo_GPIO_Port GPIOA
#define led5_Pin GPIO_PIN_5
#define led5_GPIO_Port GPIOA
#define led6_Pin GPIO_PIN_6
#define led6_GPIO_Port GPIOA
#define led7_Pin GPIO_PIN_7
#define led7_GPIO_Port GPIOA
#define amarillo_Pin GPIO_PIN_0
#define amarillo_GPIO_Port GPIOB
#define led2_Pin GPIO_PIN_10
#define led2_GPIO_Port GPIOB
#define led1_Pin GPIO_PIN_8
#define led1_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define led3_Pin GPIO_PIN_4
#define led3_GPIO_Port GPIOB
#define led4_Pin GPIO_PIN_5
#define led4_GPIO_Port GPIOB
#define led8_Pin GPIO_PIN_6
#define led8_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
