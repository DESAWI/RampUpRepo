/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file      Port_Lcfg.c
 * @author    AI.Maarouf
 * @Date	  Apr 7, 2021
 * @brief     
 ******************************************************************************
 **/
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Port.h"
#include "Port_MemMap.h"
#include "Port_Cbk.h"
#include "Dio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

const Port_ConfigType ConfigPtr[] =
{
 /*Port Name*/	     /*Pin Number*/	      /*Pin Mode*/		  /*Pin Output Type*/			/*Pin PUPDR*/                 /*Pin Speed*/
	{GPIOD, 		{PORTD_CHANNEL_12, 	PORT_PIN_OUTPUT, 	PORT_PIN_OUTPUT_PUSH_PULL, PORT_PIN_NO_PULLUP_PULLDOWN, PORT_PIN_OUTPUT_LOW_SPEED}},
	{GPIOD, 		{PORTD_CHANNEL_13, 	PORT_PIN_OUTPUT, 	PORT_PIN_OUTPUT_PUSH_PULL, PORT_PIN_NO_PULLUP_PULLDOWN, PORT_PIN_OUTPUT_LOW_SPEED}},
	{GPIOD, 		{PORTD_CHANNEL_14, 	PORT_PIN_OUTPUT, 	PORT_PIN_OUTPUT_PUSH_PULL, PORT_PIN_NO_PULLUP_PULLDOWN, PORT_PIN_OUTPUT_LOW_SPEED}},
	{GPIOD, 		{PORTD_CHANNEL_15, 	PORT_PIN_OUTPUT, 	PORT_PIN_OUTPUT_PUSH_PULL, PORT_PIN_NO_PULLUP_PULLDOWN, PORT_PIN_OUTPUT_LOW_SPEED}}
};

/***********************************End of file********************************/
