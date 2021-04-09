/**
 ******************************************************************************
 * @file           main.c
 * @author         AI.Maarouf
 * @brief          Main program body
 ******************************************************************************
 **/

#include <stdint.h>
#include <stdio.h>
#include "Port.h"
#include "Dio.h"

const Port_ConfigType ConfigPtr[NUMBER_OF_CONFIGURED_PINS];

int main(void)
{
	RCC_PORTD_CLOCK_ENABLE();
	for(uint8 index = 0; index < NUMBER_OF_CONFIGURED_PINS; index++)
	{
		Port_Init( &ConfigPtr[index] );
	}
	Dio_ReadChannel( PORTD_CHANNEL_12 );
	Dio_WriteChannel( PORTD_CHANNEL_12, STD_HIGH );
	Dio_ReadChannel( PORTD_CHANNEL_12 );
	Dio_WriteChannel( PORTD_CHANNEL_13, STD_HIGH );
	Dio_WriteChannel( PORTD_CHANNEL_14, STD_HIGH );
	Dio_WriteChannel( PORTD_CHANNEL_15, STD_HIGH );

	for(;;);
}
