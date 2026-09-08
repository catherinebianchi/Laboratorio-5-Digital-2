/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
void apagar();

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define debounce 300

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
//UART Carrera
uint8_t inicio[1];
uint8_t inicioCarrera=0;

//Jugador1
int contador1=0;
volatile unsigned long ultimo=0;
uint8_t jugador1=0;
volatile bool flag=false;

//Jugador2
int contador2=0;
volatile unsigned long ultimo2=0;
uint8_t jugador2=0;
volatile bool flag2=false;

//Ganadores
uint8_t finalista1[] = "Gana jugador 1!\r\n";
uint8_t finalista2[] = "Gana jugador 2!\r\n";

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void apagar(){
	HAL_GPIO_WritePin(GPIOA, led1_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, led2_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, led3_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, led4_Pin, 0);
	HAL_GPIO_WritePin(GPIOA, led5_Pin, 0);
	HAL_GPIO_WritePin(GPIOA, led6_Pin, 0);
	HAL_GPIO_WritePin(GPIOA, led7_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, led8_Pin, 0);

}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */


  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  //Inicio de la carrera con "s"
	  if(inicioCarrera==0){
		  contador1=0;
		  contador2=0;


		  HAL_UART_Receive(&huart2, inicio, 1, HAL_MAX_DELAY);

		  if(inicio[0]=='S'){
			  HAL_GPIO_WritePin(GPIOA, rojo_Pin, 1);
			  HAL_GPIO_WritePin(GPIOB, amarillo_Pin, 0);
			  HAL_GPIO_WritePin(verde_GPIO_Port, verde_Pin, 0);

			  HAL_Delay(1000);

			  HAL_GPIO_WritePin(GPIOA, rojo_Pin, 0);
			  HAL_GPIO_WritePin(GPIOB, amarillo_Pin, 1);
			  HAL_GPIO_WritePin(verde_GPIO_Port, verde_Pin, 0);

			  HAL_Delay(1000);

			  HAL_GPIO_WritePin(GPIOA, rojo_Pin, 0);
			  HAL_GPIO_WritePin(GPIOB, amarillo_Pin, 0);
			  HAL_GPIO_WritePin(verde_GPIO_Port, verde_Pin, 1);

			  inicioCarrera=1;
			  flag=false;
			  flag2=false;
			  jugador1=0;
			  jugador2=0;
		  }
	  }

	  if(inicioCarrera==1){
		  apagar();


		  //Jugador1
		  if(flag){
			 flag=false;
			 jugador1=1;
		  }

		  if((!flag)&&(jugador1==1)){
			  jugador1=0;
			  if(contador1<4){
			  contador1++;}
		  }

		  switch(contador1){
				  case 0: HAL_GPIO_WritePin(GPIOA, led1_Pin, 0); HAL_GPIO_WritePin(GPIOB, led2_Pin, 0); HAL_GPIO_WritePin(GPIOB, led3_Pin, 0); HAL_GPIO_WritePin(GPIOB, led4_Pin, 0); break;
				  case 1: HAL_GPIO_WritePin(GPIOA, led1_Pin, 1); HAL_GPIO_WritePin(GPIOB, led2_Pin, 0); HAL_GPIO_WritePin(GPIOB, led3_Pin, 0); HAL_GPIO_WritePin(GPIOB, led4_Pin, 0); break;
				  case 2: HAL_GPIO_WritePin(GPIOA, led1_Pin, 1); HAL_GPIO_WritePin(GPIOB, led2_Pin, 1); HAL_GPIO_WritePin(GPIOB, led3_Pin, 0); HAL_GPIO_WritePin(GPIOB, led4_Pin, 0); break;
				  case 3: HAL_GPIO_WritePin(GPIOA, led1_Pin, 1); HAL_GPIO_WritePin(GPIOB, led2_Pin, 1); HAL_GPIO_WritePin(GPIOB, led3_Pin, 1); HAL_GPIO_WritePin(GPIOB, led4_Pin, 0); break;
				  case 4: HAL_GPIO_WritePin(GPIOA, led1_Pin, 1); HAL_GPIO_WritePin(GPIOB, led2_Pin, 1); HAL_GPIO_WritePin(GPIOB, led3_Pin, 1); HAL_GPIO_WritePin(GPIOB, led4_Pin, 1); break;
				  }


		  //Jugador 2
		  if(flag2){
			  flag2=false;
			  jugador2=1;
		  }

		  if((!flag2)&&(jugador2==1)){
			  jugador2=0;
			  if(contador2<4){
			  contador2++;}
		  }

		  switch(contador2){
		  	case 0: HAL_GPIO_WritePin(GPIOA, led5_Pin, 0); HAL_GPIO_WritePin(GPIOA, led6_Pin, 0); HAL_GPIO_WritePin(GPIOA, led7_Pin, 0); HAL_GPIO_WritePin(GPIOB, led8_Pin, 0); break;
		  	case 1: HAL_GPIO_WritePin(GPIOA, led5_Pin, 1); HAL_GPIO_WritePin(GPIOA, led6_Pin, 0); HAL_GPIO_WritePin(GPIOA, led7_Pin, 0); HAL_GPIO_WritePin(GPIOB, led8_Pin, 0); break;
		  	case 2: HAL_GPIO_WritePin(GPIOA, led5_Pin, 1); HAL_GPIO_WritePin(GPIOA, led6_Pin, 1); HAL_GPIO_WritePin(GPIOA, led7_Pin, 0); HAL_GPIO_WritePin(GPIOB, led8_Pin, 0); break;
		  	case 3: HAL_GPIO_WritePin(GPIOA, led5_Pin, 1); HAL_GPIO_WritePin(GPIOA, led6_Pin, 1); HAL_GPIO_WritePin(GPIOA, led7_Pin, 1); HAL_GPIO_WritePin(GPIOB, led8_Pin, 0); break;
		  	case 4: HAL_GPIO_WritePin(GPIOA, led5_Pin, 1); HAL_GPIO_WritePin(GPIOA, led6_Pin, 1); HAL_GPIO_WritePin(GPIOA, led7_Pin, 1); HAL_GPIO_WritePin(GPIOB, led8_Pin, 1); break;
		  				  }



			if((contador1==4)&&(contador2<4)){
				HAL_UART_Transmit(&huart2, finalista1, sizeof(finalista1), 1000);
				inicioCarrera=0;
				contador1=0;
				contador2=0;
				flag=false;
				flag2=false;
				jugador1=0;
				jugador2=0;

			}
			else if((contador2==4)&&(contador1<4)){
				HAL_UART_Transmit(&huart2, finalista2, sizeof(finalista2), 1000);
				inicioCarrera=0;
				contador1=0;
				contador2=0;
				flag=false;
				flag2=false;
				jugador1=0;
				jugador2=0;

			}


	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(verde_GPIO_Port, verde_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, rojo_Pin|led5_Pin|led6_Pin|led7_Pin
                          |led1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, amarillo_Pin|led2_Pin|led3_Pin|led4_Pin
                          |led8_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : verde_Pin */
  GPIO_InitStruct.Pin = verde_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(verde_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : boton1_Pin boton2_Pin */
  GPIO_InitStruct.Pin = boton1_Pin|boton2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : rojo_Pin led5_Pin led6_Pin led7_Pin
                           led1_Pin */
  GPIO_InitStruct.Pin = rojo_Pin|led5_Pin|led6_Pin|led7_Pin
                          |led1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : amarillo_Pin led2_Pin led3_Pin led4_Pin
                           led8_Pin */
  GPIO_InitStruct.Pin = amarillo_Pin|led2_Pin|led3_Pin|led4_Pin
                          |led8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){

	//Jugador 1
	if(GPIO_Pin == boton1_Pin){
		unsigned long ahora = HAL_GetTick();
		if(ahora - ultimo > debounce){
			flag=true;
			ultimo=ahora;
		}
	}

	//Jugador 2
	if(GPIO_Pin == boton2_Pin){
			unsigned long ahora2 = HAL_GetTick();
			if(ahora2 - ultimo2 > debounce){
				flag2=true;
				ultimo2=ahora2;
			}
		}
}



/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
