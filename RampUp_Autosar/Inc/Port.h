/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file      Port.h
 * @author    AI.Maarouf
 * @Date	  Apr 7, 2021
 * @brief     
 ******************************************************************************
 **/
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef PORT_H_
#define PORT_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Port_Cfg.h"
#include "Std_Types.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

typedef uint8 Port_PinType;  				/*Data type for the symbolic name of a port pin.*/
typedef uint8 Port_PinDirectionType; 		/*Possible directions of a port pin.*/
typedef uint8 Port_PinModeType;				/*Different port pin modes.*/
typedef uint8 Port_PinOutputType;			/*GPIO port output type*/
typedef uint8 Port_PinOutputSpeedType;		/*GPIO port output speed*/
typedef uint8 Port_PinPuPdType;				/*GPIO port PuPd type*/

/*structure for the external data structure containing the initialization data for this module.*/
typedef struct
{
	volatile uint32 Port_ModeR;
	volatile uint32 Port_OutTypeR;
	volatile uint32 Port_OutSpeedR;
	volatile uint32 Port_PuPdR;
	volatile uint32 Port_IDR;
	volatile uint32 Port_ODR;
	volatile uint32 Port_BSSR;
	volatile uint32 Port_LCKR;
	volatile uint32 Port_AFRL;
	volatile uint32 Port_AFRH;
}Port_RegConfigType;

typedef struct
{
	Port_PinType 			Port_PinNumber;
	Port_PinModeType 		Port_PinMode;
	Port_PinOutputType		Port_PinOutputType;
	Port_PinPuPdType		Port_PinPuPdType;
	Port_PinOutputSpeedType	Port_PinOutputSpeed;
}Port_PinConfigType;

typedef struct
{
	Port_RegConfigType* Port_RegisterConfig;
	Port_PinConfigType Port_PinConfig;
}Port_ConfigType;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern const Port_ConfigType ConfigPtr[];
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/*GPIO port mode*/
#define PORT_PIN_INPUT								(0x00U)
#define PORT_PIN_OUTPUT								(0x01U)
#define PORT_PIN_ALTERNATE_FUNCTION					(0x10U)
#define PORT_PIN_ANALOG								(0x11U)
/*GPIO port output type*/
#define PORT_PIN_OUTPUT_PUSH_PULL					(0x00U)
#define PORT_PIN_OUTPUT_OPEN_DRAIN					(0x01U)
/*GPIO port output speed*/
#define PORT_PIN_OUTPUT_LOW_SPEED					(0x00U)
#define PORT_PIN_OUTPUT_MEDIUM_SPEED				(0x01U)
#define PORT_PIN_OUTPUT_FAST_SPEED					(0x10U)
#define PORT_PIN_OUTPUT_HIGH_SPEED					(0x11U)

/*GPIO port pull-up/pull-down*/
#define PORT_PIN_NO_PULLUP_PULLDOWN					(0x00U)
#define PORT_PIN_PULLUP								(0x01U)
#define PORT_PIN_PULLDOWN							(0x10U)

#define GPIOA										((Port_RegConfigType*)0x40020000U)
#define GPIOB										((Port_RegConfigType*)0x40020400U)
#define GPIOC										((Port_RegConfigType*)0x40020800U)
#define GPIOD										((Port_RegConfigType*)0x40020C00U)
#define GPIOE										((Port_RegConfigType*)0x40021000U)
#define GPIOH										((Port_RegConfigType*)0x40021C00U)


#define RCC_BASE_ADDRESS							((volatile uint32*)(0x40023800U))
#define RCC_AHB1ENR									((volatile uint32*)(0x40023800U + 0x30))
#define RCC_GPIOAEN_BIT								(0)
#define RCC_GPIOBEN_BIT								(1)
#define RCC_GPIOCEN_BIT								(2)
#define RCC_GPIODEN_BIT								(3)
#define RCC_GPIOEEN_BIT								(4)
#define RCC_GPIOHEN_BIT								(7)
#define RCC_PORTA_CLOCK_ENABLE()					((*RCC_AHB1ENR) |= (STD_ENABLE << RCC_GPIOAEN_BIT))
#define RCC_PORTB_CLOCK_ENABLE()					((*RCC_AHB1ENR) |= (STD_ENABLE << RCC_GPIOBEN_BIT))
#define RCC_PORTC_CLOCK_ENABLE()					((*RCC_AHB1ENR) |= (STD_ENABLE << RCC_GPIOCEN_BIT))
#define RCC_PORTD_CLOCK_ENABLE()					((*RCC_AHB1ENR) |= (STD_ENABLE << RCC_GPIODEN_BIT))
#define RCC_PORTE_CLOCK_ENABLE()					((*RCC_AHB1ENR) |= (STD_ENABLE << RCC_GPIOEEN_BIT))
#define RCC_PORTH_CLOCK_ENABLE()					((*RCC_AHB1ENR) |= (STD_ENABLE << RCC_GPIOHEN_BIT))


/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */
/**
  * @brief  				Initializes the Port Driver module.
  * @Sync/Async				Synchronous.
  * @Reentrancy				Non Reentrant.
  * @Parameters (in)  		Pointer to configuration set.
  * @Parameters (out)		None.
  * @Parameters (inout)		None.
  * @retval 				None.
  */
void Port_Init( const Port_ConfigType* ConfigPtr );
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
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
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
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );
/**
  * @brief  				Refreshes port direction.
  * @Sync/Async				Synchronous.
  * @Reentrancy				Non Reentrant.
  * @Parameters (in)  		None.
  * @Parameters (out)		None.
  * @Parameters (inout)		None.
  * @retval 				None.
  */
void Port_RefreshPortDirection( void );
/**
  * @brief  				Returns the version information of this module.
  * @Sync/Async				Synchronous.
  * @Reentrancy				Reentrant.
  * @Parameters (in)  		None.
  * @Parameters (out)		Pointer to where to store the version information of this module.
  * @Parameters (inout)		None.
  * @retval 				None.
  */
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* PORT_H_ */

/*****************************END OF FILE*****************************/
