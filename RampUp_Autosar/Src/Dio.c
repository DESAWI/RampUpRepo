/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file      Dio.c
 * @author    AI.Maarouf
 * @Date	  Apr 7, 2021
 * @brief
 ******************************************************************************
 **/
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Dio.h"
#include "Dio_MemMap.h"
#include "SchM_Dio.h"
#include "Det.h"
#include "Port.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define MAX_CHANNEL_PER_PORT		(8U)
#define OUTPUT_DATA_REGISTER		(PortRegConf.Port_RegisterConfig -> Port_ODR)
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/

/* USER CODE BEGIN PFP */
static Dio_LevelType Dio_PortHighIOConfCheck(Port_ConfigType PortRegConf, Dio_ChannelType ChannelId);
static Dio_LevelType Dio_PortLowIOConfCheck(Port_ConfigType PortRegConf, Dio_ChannelType ChannelId);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
static Dio_LevelType Dio_PortHighIOConfCheck(Port_ConfigType PortRegConf, Dio_ChannelType ChannelId)
{
	Dio_LevelType 	RetVal = STD_LOW;
	if(((PortRegConf.Port_RegisterConfig -> Port_ModeR >> ((ChannelId + 8) * 2))&0x01) == PORT_PIN_OUTPUT)
	{
		RetVal = (Dio_LevelType)((PortRegConf.Port_RegisterConfig -> Port_ODR >> (ChannelId + 8)) & 0x01);
	}
	else if(((PortRegConf.Port_RegisterConfig -> Port_ModeR >> ((ChannelId + 8) * 2))&0x01) == PORT_PIN_INPUT)
	{
		RetVal = (Dio_LevelType)((PortRegConf.Port_RegisterConfig -> Port_IDR >> (ChannelId + 8)) & 0x01);
	}
	return RetVal;
}

static Dio_LevelType Dio_PortLowIOConfCheck(Port_ConfigType PortRegConf, Dio_ChannelType ChannelId)
{
	Dio_LevelType 	RetVal = STD_LOW;
	if(((PortRegConf.Port_RegisterConfig -> Port_ModeR >> (ChannelId / 2))&0x11) == PORT_PIN_OUTPUT)
	{
		RetVal = (Dio_LevelType)((PortRegConf.Port_RegisterConfig -> Port_ODR >> ChannelId) & 0x01);
	}
	else if(((PortRegConf.Port_RegisterConfig -> Port_ModeR >> (ChannelId / 2))&0x11) == PORT_PIN_INPUT)
	{
		RetVal = (Dio_LevelType)((PortRegConf.Port_RegisterConfig -> Port_IDR >> ChannelId) & 0x01);
	}
	return RetVal;
}
/**
  * @brief  				function shall return the value of the specified DIO channel.
  * @Sync/Async				Synchronous.
  * @Reentrancy				Reentrant.
  * @Parameters (in)  		ID of DIO channel.
  * @Parameters (out)		None.
  * @Parameters (inout)		None.
  * @retval 				The physical level of the corresponding Pin.
  */

Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
{
	Dio_LevelType 	RetVal = STD_LOW;
	Port_ConfigType PortRegConf;
	Dio_PortType 	LocPortId;
	Dio_ChannelType LocChannelId;
	LocPortId 	 = 	(ChannelId / MAX_CHANNEL_PER_PORT);
	LocChannelId = 	(ChannelId % MAX_CHANNEL_PER_PORT);
	switch(LocPortId)
	{
	case PORTA_LOW:
		PortRegConf.Port_RegisterConfig = GPIOA;
		RetVal = Dio_PortLowIOConfCheck(PortRegConf, LocChannelId);
		break;
	case PORTA_HIGH:
		PortRegConf.Port_RegisterConfig = GPIOA;
		RetVal = Dio_PortHighIOConfCheck(PortRegConf, LocChannelId);
		break;
	case PORTB_LOW:
		PortRegConf.Port_RegisterConfig = GPIOB;
		RetVal = Dio_PortLowIOConfCheck(PortRegConf, LocChannelId);
		break;
	case PORTB_HIGH:
		PortRegConf.Port_RegisterConfig = GPIOB;
		RetVal = Dio_PortHighIOConfCheck(PortRegConf, LocChannelId);
		break;
	case PORTC_LOW:
		PortRegConf.Port_RegisterConfig = GPIOC;
		RetVal = Dio_PortLowIOConfCheck(PortRegConf, LocChannelId);
		break;
	case PORTC_HIGH:
		PortRegConf.Port_RegisterConfig = GPIOC;
		RetVal = Dio_PortHighIOConfCheck(PortRegConf, LocChannelId);
	break;
	case PORTD_LOW:
		PortRegConf.Port_RegisterConfig = GPIOD;
		RetVal = Dio_PortLowIOConfCheck(PortRegConf, LocChannelId);
		break;
	case PORTD_HIGH:
		PortRegConf.Port_RegisterConfig = GPIOD;
		RetVal = Dio_PortHighIOConfCheck(PortRegConf, LocChannelId);
		break;
	case PORTE_LOW:
		PortRegConf.Port_RegisterConfig = GPIOE;
		RetVal = Dio_PortLowIOConfCheck(PortRegConf, LocChannelId);
		break;
	case PORTE_HIGH:
		PortRegConf.Port_RegisterConfig = GPIOE;
		RetVal = Dio_PortHighIOConfCheck(PortRegConf, LocChannelId);
		break;
	case PORTH_LOW:
		PortRegConf.Port_RegisterConfig = GPIOH;
		RetVal = Dio_PortLowIOConfCheck(PortRegConf, LocChannelId);
		break;
	case PORTH_HIGH:
		PortRegConf.Port_RegisterConfig = GPIOH;
		RetVal = Dio_PortHighIOConfCheck(PortRegConf, LocChannelId);
		break;
	default:
		/*Shouldn't be here*/
		break;
	}
	return RetVal;
}

/**
  * @brief  				Service to set a level of a channel.
  * @Sync/Async				Synchronous.
  * @Reentrancy				Reentrant.
  * @Parameters (in#1)  	ID of DIO channel.
  * @Parameters (in#2)		Value to be written.
  * @Parameters (out)		None.
  * @Parameters (inout)		None.
  * @retval 				None.
  */

void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
	Port_ConfigType PortRegConf;
	Dio_PortType 	LocPortId;
	Dio_ChannelType LocChannelId;
	LocPortId 	 = 	(ChannelId / MAX_CHANNEL_PER_PORT);
	LocChannelId = 	(ChannelId % MAX_CHANNEL_PER_PORT);
	switch(LocPortId)
	{
	case PORTA_LOW:
		PortRegConf.Port_RegisterConfig = GPIOA;
		OUTPUT_DATA_REGISTER |=  (Level << LocChannelId);
		break;
	case PORTA_HIGH:
		PortRegConf.Port_RegisterConfig = GPIOA;
		OUTPUT_DATA_REGISTER |=  (Level << (LocChannelId + 8));
		break;
	case PORTB_LOW:
		PortRegConf.Port_RegisterConfig = GPIOB;
		OUTPUT_DATA_REGISTER |=  (Level << LocChannelId);
		break;
	case PORTB_HIGH:
		PortRegConf.Port_RegisterConfig = GPIOB;
		OUTPUT_DATA_REGISTER |=  (Level << (LocChannelId + 8));
		break;
	case PORTC_LOW:
		PortRegConf.Port_RegisterConfig = GPIOC;
		OUTPUT_DATA_REGISTER |=  (Level << LocChannelId);
		break;
	case PORTC_HIGH:
		PortRegConf.Port_RegisterConfig = GPIOC;
		OUTPUT_DATA_REGISTER |=  (Level << (LocChannelId + 8));
		break;
	case PORTD_LOW:
		PortRegConf.Port_RegisterConfig = GPIOD;
		OUTPUT_DATA_REGISTER |=  (Level << LocChannelId);
		break;
	case PORTD_HIGH:
		PortRegConf.Port_RegisterConfig = GPIOD;
		OUTPUT_DATA_REGISTER |=  (Level << (LocChannelId + 8));
		break;
	case PORTE_LOW:
		PortRegConf.Port_RegisterConfig = GPIOE;
		OUTPUT_DATA_REGISTER |=  (Level << LocChannelId);
		break;
	case PORTE_HIGH:
		PortRegConf.Port_RegisterConfig = GPIOE;
		OUTPUT_DATA_REGISTER |=  (Level << (LocChannelId + 8));
		break;
	case PORTH_LOW:
		PortRegConf.Port_RegisterConfig = GPIOH;
		OUTPUT_DATA_REGISTER |=  (Level << LocChannelId);
		break;
	case PORTH_HIGH:
		PortRegConf.Port_RegisterConfig = GPIOH;
		OUTPUT_DATA_REGISTER |=  (Level << (LocChannelId + 8));
		break;
	default:
		/*Shouldn't be here*/
		break;
	}
}

/**
  * @brief  				function shall Return the level of all channels of that port.
  * @Sync/Async				Synchronous.
  * @Reentrancy				Reentrant.
  * @Parameters (in)  		ID of DIO Port.
  * @Parameters (out)		None.
  * @Parameters (inout)		None.
  * @retval 				The physical level of all channels of that port.
  */

Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )
{
	Dio_PortLevelType RetVal = STD_LOW;

	return RetVal;
}

/**
  * @brief  				Service to set a value of the port.
  * @Sync/Async				Synchronous.
  * @Reentrancy				Reentrant.
  * @Parameters (in#1)  	ID of DIO Port.
  * @Parameters (in#2)		Value to be written.
  * @Parameters (out)		None.
  * @Parameters (inout)		None.
  * @retval 				None.
  */

void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level )
{

}

/**
  * @brief  				This Service reads a subset of the adjoining bits of a port.
  * @Sync/Async				Synchronous.
  * @Reentrancy				Reentrant.
  * @Parameters (in)  		Pointer to ChannelGroup.
  * @Parameters (out)		None.
  * @Parameters (inout)		None.
  * @retval 				Level of a subset of the adjoining bits of a port.
  */

Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr )
{
	Dio_PortLevelType RetVal = STD_LOW;

	return RetVal;
}

/**
  * @brief  				Service to set a subset of the adjoining bits of a port to a specified level.
  * @Sync/Async				Synchronous.
  * @Reentrancy				Reentrant.
  * @Parameters (in#1)  	Pointer to ChannelGroup.
  * @Parameters (in#2)		Value to be written.
  * @Parameters (out)		None.
  * @Parameters (inout)		None.
  * @retval 				None.
  */

void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level )
{

}

/**
  * @brief  				Service to flip (change from 1 to 0 or from 0 to 1) the level
  * 						of a channel and return the level of the channel after flip.
  * @Sync/Async				Synchronous.
  * @Reentrancy				Reentrant.
  * @Parameters (in)  		ID of DIO channel.
  * @Parameters (out)		None.
  * @Parameters (inout)		None.
  * @retval 				The physical level of the corresponding Pin.
  */

Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId )
{
	Dio_LevelType RetVal = STD_LOW;

	return RetVal;
}

/**
  * @brief  				Service to get the version information of this module.
  * @Sync/Async				Synchronous.
  * @Reentrancy				Reentrant.
  * @Parameters (in)  		None.
  * @Parameters (out)		Pointer to where to store the version information of this module.
  * @Parameters (inout)		None.
  * @retval 				None.
  */

void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo )
{

}

