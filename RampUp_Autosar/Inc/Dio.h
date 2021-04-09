/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file      Dio.h
 * @author    AI.Maarouf
 * @Date	  Apr 7, 2021
 * @brief
 ******************************************************************************
 **/
/* USER CODE END Header */

#ifndef DIO_H_
#define DIO_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Std_Types.h"
#include "Dio_Cfg.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;
typedef uint8 Dio_LevelType;
typedef uint8 Dio_PortLevelType;

/**
  * @brief DIO Channel group structure definition
  */

typedef struct
{
	uint8 			mask;
	uint8 			offset;
	Dio_PortType 	port;
}Dio_ChannelGroupType;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* Port#0 : PortA Low Byte */
#define PORTA_LOW						(0U)
#define PORTA_CHANNEL_00				(0U)
#define PORTA_CHANNEL_01				(1U)
#define PORTA_CHANNEL_02				(2U)
#define PORTA_CHANNEL_03				(3U)
#define PORTA_CHANNEL_04				(4U)
#define PORTA_CHANNEL_05				(5U)
#define PORTA_CHANNEL_06				(6U)
#define PORTA_CHANNEL_07				(7U)

/* Port#1 : PortA High Byte */
#define PORTA_HIGH						(1U)
#define PORTA_CHANNEL_08				(8U)
#define PORTA_CHANNEL_09				(9U)
#define PORTA_CHANNEL_10				(10U)
#define PORTA_CHANNEL_11				(11U)
#define PORTA_CHANNEL_12				(12U)
#define PORTA_CHANNEL_13				(13U)
#define PORTA_CHANNEL_14				(14U)
#define PORTA_CHANNEL_15				(15U)

/* Port#2 : PortB Low Byte */
#define PORTB_LOW						(2U)
#define PORTB_CHANNEL_00				(16U)
#define PORTB_CHANNEL_01				(17U)
#define PORTB_CHANNEL_02				(18U)
#define PORTB_CHANNEL_03				(19U)
#define PORTB_CHANNEL_04				(20U)
#define PORTB_CHANNEL_05				(21U)
#define PORTB_CHANNEL_06				(22U)
#define PORTB_CHANNEL_07				(23U)

/* Port#3 : PortB High Byte */
#define PORTB_HIGH						(3U)
#define PORTB_CHANNEL_08				(24U)
#define PORTB_CHANNEL_09				(25U)
#define PORTB_CHANNEL_10				(26U)
#define PORTB_CHANNEL_11				(27U)
#define PORTB_CHANNEL_12				(28U)
#define PORTB_CHANNEL_13				(29U)
#define PORTB_CHANNEL_14				(30U)
#define PORTB_CHANNEL_15				(31U)

/* Port#4 : PortC Low Byte */
#define PORTC_LOW						(4U)
#define PORTC_CHANNEL_00				(32U)
#define PORTC_CHANNEL_01				(33U)
#define PORTC_CHANNEL_02				(34U)
#define PORTC_CHANNEL_03				(35U)
#define PORTC_CHANNEL_04				(36U)
#define PORTC_CHANNEL_05				(37U)
#define PORTC_CHANNEL_06				(38U)
#define PORTC_CHANNEL_07				(39U)

/* Port#5 : PortC High Byte */
#define PORTC_HIGH						(5U)
#define PORTC_CHANNEL_08				(40U)
#define PORTC_CHANNEL_09				(41U)
#define PORTC_CHANNEL_10				(42U)
#define PORTC_CHANNEL_11				(43U)
#define PORTC_CHANNEL_12				(44U)
#define PORTC_CHANNEL_13				(45U)
#define PORTC_CHANNEL_14				(46U)
#define PORTC_CHANNEL_15				(47U)

/* Port#6 : PortD Low Byte */
#define PORTD_LOW						(6U)
#define PORTD_CHANNEL_00				(48U)
#define PORTD_CHANNEL_01				(49U)
#define PORTD_CHANNEL_02				(50U)
#define PORTD_CHANNEL_03				(51U)
#define PORTD_CHANNEL_04				(52U)
#define PORTD_CHANNEL_05				(53U)
#define PORTD_CHANNEL_06				(54U)
#define PORTD_CHANNEL_07				(55U)

/* Port#7 : PortD High Byte */
#define PORTD_HIGH						(7U)
#define PORTD_CHANNEL_08				(56U)
#define PORTD_CHANNEL_09				(57U)
#define PORTD_CHANNEL_10				(58U)
#define PORTD_CHANNEL_11				(59U)
#define PORTD_CHANNEL_12				(60U)
#define PORTD_CHANNEL_13				(61U)
#define PORTD_CHANNEL_14				(62U)
#define PORTD_CHANNEL_15				(63U)

/* Port#8 : PortE Low Byte */
#define PORTE_LOW						(8U)
#define PORTE_CHANNEL_00				(64U)
#define PORTE_CHANNEL_01				(65U)
#define PORTE_CHANNEL_02				(66U)
#define PORTE_CHANNEL_03				(67U)
#define PORTE_CHANNEL_04				(68U)
#define PORTE_CHANNEL_05				(69U)
#define PORTE_CHANNEL_06				(70U)
#define PORTE_CHANNEL_07				(71U)

/* Port#9 : PortE High Byte */
#define PORTE_HIGH						(9U)
#define PORTE_CHANNEL_08				(72U)
#define PORTE_CHANNEL_09				(73U)
#define PORTE_CHANNEL_10				(74U)
#define PORTE_CHANNEL_11				(75U)
#define PORTE_CHANNEL_12				(76U)
#define PORTE_CHANNEL_13				(77U)
#define PORTE_CHANNEL_14				(78U)
#define PORTE_CHANNEL_15				(79U)

/* Port#10 : PortH Low Byte */
#define PORTH_LOW						(10U)
#define PORTH_CHANNEL_00				(80U)
#define PORTH_CHANNEL_01				(81U)
#define PORTH_CHANNEL_02				(82U)
#define PORTH_CHANNEL_03				(83U)
#define PORTH_CHANNEL_04				(84U)
#define PORTH_CHANNEL_05				(85U)
#define PORTH_CHANNEL_06				(86U)
#define PORTH_CHANNEL_07				(87U)

/* Port#11 : PortH High Byte */
#define PORTH_HIGH						(11U)
#define PORTH_CHANNEL_08				(88U)
#define PORTH_CHANNEL_09				(89U)
#define PORTH_CHANNEL_10				(90U)
#define PORTH_CHANNEL_11				(91U)
#define PORTH_CHANNEL_12				(92U)
#define PORTH_CHANNEL_13				(93U)
#define PORTH_CHANNEL_14				(94U)
#define PORTH_CHANNEL_15				(95U)

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/

/* USER CODE BEGIN EFP */
Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId );
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level );
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId );
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level );
Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr );
void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level );
void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo );
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId );
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/*****************************END OF FILE*****************************/
