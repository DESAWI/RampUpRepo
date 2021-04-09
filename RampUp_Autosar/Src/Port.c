/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file      Port.c
 * @author    AI.Maarouf
 * @Date	  Apr 7, 2021
 * @brief     
 ******************************************************************************
 **/
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdint.h>
#include <stdio.h>
#include "Port.h"
#include "Port_MemMap.h"
#include "SchM_Port.h"
#include "Det.h"
#include "Port_Cbk.h"
#include "Std_Types.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */
#define PORT_REGISTER_CONFIG_STRUCTURE 		(ConfigPtr -> Port_RegisterConfig)
#define PORT_PIN_CONFIG_STRUCTURE			(ConfigPtr -> Port_PinConfig)
#define MAX_PORT_PIN_NUMBER					(8U)
/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/

/* USER CODE BEGIN PFP */
static void Port_PinConfig(const Port_ConfigType* ConfigPtr, Port_PinType PinNmber);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/

/* USER CODE BEGIN 0 */
static void Port_PinConfig(const Port_ConfigType* ConfigPtr, Port_PinType PinNmber)
{
	(PORT_REGISTER_CONFIG_STRUCTURE -> Port_ModeR) |= \
			(PORT_PIN_CONFIG_STRUCTURE.Port_PinMode << (PinNmber * 2));
	(PORT_REGISTER_CONFIG_STRUCTURE -> Port_OutTypeR) |= \
			(PORT_PIN_CONFIG_STRUCTURE.Port_PinOutputType << PinNmber);
	(PORT_REGISTER_CONFIG_STRUCTURE -> Port_OutSpeedR) |= \
			(PORT_PIN_CONFIG_STRUCTURE.Port_PinOutputSpeed << (PinNmber * 2));
	(PORT_REGISTER_CONFIG_STRUCTURE -> Port_PuPdR) |= \
			(PORT_PIN_CONFIG_STRUCTURE.Port_PinPuPdType << (PinNmber * 2));
}
/* USER CODE END 0 */

/**
  * @brief  				Initializes the Port Driver module.
  * @Sync/Async				Synchronous.
  * @Reentrancy				Non Reentrant.
  * @Parameters (in)  		Pointer to configuration set.
  * @Parameters (out)		None.
  * @Parameters (inout)		None.
  * @retval 				None.
  */
void Port_Init( const Port_ConfigType* ConfigPtr )
{
	Port_PinType LocPinNmber;
	uint8 		 LocPortNumber;
	LocPortNumber = (PORT_PIN_CONFIG_STRUCTURE.Port_PinNumber / MAX_PORT_PIN_NUMBER);
	LocPinNmber   = (PORT_PIN_CONFIG_STRUCTURE.Port_PinNumber % MAX_PORT_PIN_NUMBER);
	if(ConfigPtr != NULL)
	{
		if(! (LocPortNumber % 2))
		{
			Port_PinConfig( ConfigPtr, LocPinNmber );
		}
		else if(LocPortNumber % 2)
		{
			LocPinNmber += MAX_PORT_PIN_NUMBER;
			Port_PinConfig( ConfigPtr, LocPinNmber );
		}
	}
}
/**
  * @brief  				Sets the port pin direction.
  * @Sync/Async				Synchronous.
  * @Reentrancy				Reentrant.
  * @Parameters (in#1)  	Port Pin ID number.
  * @Parameters (in#2)		Port Pin Direction.
  * @Parameters (out)		None.
  * @Parameters (inout)		None.
  * @retval 				None.
  */
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{

}
/**
  * @brief  				Sets the port pin mode.
  * @Sync/Async				Synchronous.
  * @Reentrancy				Reentrant.
  * @Parameters (in#1)  	Port Pin ID number.
  * @Parameters (in#2)		New Port Pin mode to be set on port pin.
  * @Parameters (out)		None
  * @Parameters (inout)		None.
  * @retval 				None.
  */
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{

}
/**
  * @brief  				Refreshes port direction.
  * @Sync/Async				Synchronous.
  * @Reentrancy				Non Reentrant.
  * @Parameters (in)  		None.
  * @Parameters (out)		None.
  * @Parameters (inout)		None.
  * @retval 				None.
  */
void Port_RefreshPortDirection( void )
{

}
/**
  * @brief  				Returns the version information of this module.
  * @Sync/Async				Synchronous.
  * @Reentrancy				Reentrant.
  * @Parameters (in)  		None.
  * @Parameters (out)		Pointer to where to store the version information of this module.
  * @Parameters (inout)		None.
  * @retval 				None.
  */
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{

}

