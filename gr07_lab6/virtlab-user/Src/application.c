/*
 * application.c
 *
 *  Created on: Oct 20, 2020
 *      Author: max
 */

#include "main.h"
#include "cmsis_os2.h"
#include "io.h"
#include "usbserial.h"

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc3;

extern COMP_HandleTypeDef hcomp1;

extern DAC_HandleTypeDef hdac1;

extern LCD_HandleTypeDef hlcd;

extern OPAMP_HandleTypeDef hopamp1;
extern OPAMP_HandleTypeDef hopamp2;

void StartDefaultTask( void *argument ) {
	while( 1 ) {
		// Read switch status, and select related demo
		led3( ON );
		osDelay( 100 );
		led3( OFF );
		if( GET_SWITCH( 0 ) ) {
			// Sample 1: just toggle IO0 for 60 seconds
			LL_GPIO_SetPinMode( IO0_GPIO_Port, IO0_Pin,	LL_GPIO_MODE_OUTPUT );
			for( int i = 0; i < 60; i++ ) {
				osDelay( 900 );
				led0( ON );
				LL_GPIO_TogglePin( IO0_GPIO_Port, IO0_Pin );
				osDelay( 100 );
				led0( OFF );
				LL_GPIO_TogglePin( IO0_GPIO_Port, IO0_Pin );
			}
		} else if( GET_SWITCH( 1 ) ) {
			// Sample 2: Generate analog signal using DAC channel 1 for 60 seconds
			for( int i = 0; i < 50 * 60; i++ ) {
				HAL_DAC_SetValue( &hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 128 + 10 );
				led0( ON );
				led2( ON );
				led3( ON );
				// Copy status of switch 7 to user MCU led 1
				if(	GET_SWITCH( 7 ) ) {
					led1( ON );
				};
				osDelay( 10 );
				HAL_DAC_SetValue( &hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 128 - 10 );
				led0( OFF );
				led1( OFF );
				led2( OFF );
				led3( OFF );
				osDelay( 10 );
			}
		} else if( GET_SWITCH( 2 ) ) {
			// Sample 3: USB virtual serial echo (limited to 100 characters)
			for( int i = 0; i < 100; i++ ) {
				uint8_t ch = usbserialReadChar();
				usbserialWriteChar( ch );
			}
		} else if( GET_SWITCH( 3 ) ) {
			// Sample 4: LCD display (10 seconds)
			for( int i = 0; i < 10; i++ ) {
				lcdWriteHexDigit( i, 0 );
				lcdUpdateDisplay();
				osDelay( 1000 );
			}
			lcdWriteDigit( ' ', 0 );
			lcdUpdateDisplay();
		}
	}
}

