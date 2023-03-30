/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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

//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

extern ADC_HandleTypeDef 	hadc1;
extern CAN_HandleTypeDef 	hcan1;
extern I2C_HandleTypeDef 	hi2c2;
extern RTC_HandleTypeDef 	hrtc;
extern TIM_HandleTypeDef 	htim1;
extern UART_HandleTypeDef 	huart5;

extern void App_MAIN(void);
//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define OUT_CELL1_Pin GPIO_PIN_2
#define OUT_CELL1_GPIO_Port GPIOF
#define OUT_CELL2_Pin GPIO_PIN_3
#define OUT_CELL2_GPIO_Port GPIOF
#define OUT_CELL3_Pin GPIO_PIN_4
#define OUT_CELL3_GPIO_Port GPIOF
#define OUT_CELL4_Pin GPIO_PIN_5
#define OUT_CELL4_GPIO_Port GPIOF
#define OUT_CELL5_Pin GPIO_PIN_6
#define OUT_CELL5_GPIO_Port GPIOF
#define OUT_CELL6_Pin GPIO_PIN_7
#define OUT_CELL6_GPIO_Port GPIOF
#define OUT_CELL7_Pin GPIO_PIN_8
#define OUT_CELL7_GPIO_Port GPIOF
#define OUT_CELL8_Pin GPIO_PIN_9
#define OUT_CELL8_GPIO_Port GPIOF
#define OUT_CELL9_Pin GPIO_PIN_10
#define OUT_CELL9_GPIO_Port GPIOF
#define OUT_CELL10_Pin GPIO_PIN_0
#define OUT_CELL10_GPIO_Port GPIOC
#define OUT_CELL11_Pin GPIO_PIN_1
#define OUT_CELL11_GPIO_Port GPIOC
#define OUT_CELL12_Pin GPIO_PIN_2
#define OUT_CELL12_GPIO_Port GPIOC
#define OUT_CELL13_Pin GPIO_PIN_3
#define OUT_CELL13_GPIO_Port GPIOC
#define OUT_CELL14_Pin GPIO_PIN_4
#define OUT_CELL14_GPIO_Port GPIOA
#define OUT_CELL15_Pin GPIO_PIN_5
#define OUT_CELL15_GPIO_Port GPIOA
#define OUT_CELL16_Pin GPIO_PIN_6
#define OUT_CELL16_GPIO_Port GPIOA
#define OUT_CELL17_Pin GPIO_PIN_7
#define OUT_CELL17_GPIO_Port GPIOA
#define OUT_CELL18_Pin GPIO_PIN_4
#define OUT_CELL18_GPIO_Port GPIOC
#define M1_S0_Pin GPIO_PIN_13
#define M1_S0_GPIO_Port GPIOF
#define M1_S1_Pin GPIO_PIN_14
#define M1_S1_GPIO_Port GPIOF
#define M1_S2_Pin GPIO_PIN_15
#define M1_S2_GPIO_Port GPIOF
#define M2_S0_Pin GPIO_PIN_0
#define M2_S0_GPIO_Port GPIOG
#define M2_S1_Pin GPIO_PIN_1
#define M2_S1_GPIO_Port GPIOG
#define M2_S2_Pin GPIO_PIN_7
#define M2_S2_GPIO_Port GPIOE
#define M3_S0_Pin GPIO_PIN_10
#define M3_S0_GPIO_Port GPIOE
#define M3_S1_Pin GPIO_PIN_11
#define M3_S1_GPIO_Port GPIOE
#define M3_S2_Pin GPIO_PIN_12
#define M3_S2_GPIO_Port GPIOE
#define M0_S0_Pin GPIO_PIN_15
#define M0_S0_GPIO_Port GPIOA
#define M0_S1_Pin GPIO_PIN_10
#define M0_S1_GPIO_Port GPIOC
#define M0_S2_Pin GPIO_PIN_11
#define M0_S2_GPIO_Port GPIOC
#define D_SET_Pin GPIO_PIN_0
#define D_SET_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
