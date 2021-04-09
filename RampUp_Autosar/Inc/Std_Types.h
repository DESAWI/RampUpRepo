/**
 ******************************************************************************
 * @file      Std_Types.h
 * @author    AI.Maarouf
 * @Date	  Apr 7, 2021
 * @brief
 ******************************************************************************
 **/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include "Compiler.h"
#include "Platform_Types.h"

typedef uint8 Std_ReturnType;
#define E_OK			(0x00U)
#define E_NOT_OK		(0x01U)
#define STD_OFF			(0x00U)
#define STD_ON			(0x01U)
#define STD_LOW			(0x00U)	/* Physical state 0V */
#define STD_HIGH		(0x01U)	/* Physical state 5V or 3.3V */
#define STD_IDLE		(0x00U)	/* Logical state idle */
#define STD_ACTIVE		(0x01U)	/* Logical state active */
#define STD_DISABLE		(0x00U)
#define STD_ENABLE		(0x01U)


#define NULL ((void *)0)

typedef struct
{
 uint16 vendorID;
 uint16 moduleID;
 uint8 instanceID;
 uint8 sw_major_version;
 uint8 sw_minor_version;
 uint8 sw_patch_version;
} Std_VersionInfoType;



#endif /* STD_TYPES_H_ */
