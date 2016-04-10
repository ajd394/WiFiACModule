//*****************************************************************************
// gpio_if.c
//
//*****************************************************************************

// Standard includes
#include <stdio.h>

// Driverlib includes
#include "hw_types.h"
#include "hw_ints.h"
#include "hw_memmap.h"
#include "hw_apps_rcm.h"
#include "interrupt.h"
#include "pin.h"
#include "gpio.h"
#include "prcm.h"
#include "rom.h"
#include "rom_map.h"

// OS includes
#if defined(USE_TIRTOS) || defined(USE_FREERTOS) || defined(SL_PLATFORM_MULTI_THREADED)
#include <stdlib.h>
#include "osi.h"
#endif

// Common interface include
#include "gpio_if.h"
#include "gpio_functions.h"

// Local Variables - Start

unsigned int g_uiCOMPRESSORPort = 0,g_uiFAN_LOWPort = 0,g_uiFAN_MEDPort = 0,g_uiFAN_HIGHPort = 0;
unsigned char g_ucCOMPRESSORPin,g_ucFAN_LOWPin,g_ucFAN_MEDPin,g_ucFAN_HIGHPin;

#define GPIO_COMPRESSOR 6
#define GPIO_FAN_LOW 7
#define GPIO_FAN_MED 25
#define GPIO_FAN_HIGH 15

// Local Variables - End

// GPIO Enabling and Configuration - Start

void
ac_GPIO_Configure()
{

    GPIO_IF_GetPortNPin(GPIO_COMPRESSOR,
                        &g_uiCOMPRESSORPort,
                        &g_ucCOMPRESSORPin);

    GPIO_IF_GetPortNPin(GPIO_FAN_LOW,
                  &g_uiFAN_LOWPort,
				  &g_ucFAN_LOWPin);

    GPIO_IF_GetPortNPin(GPIO_FAN_MED,
                      &g_uiFAN_MEDPort,
                      &g_ucFAN_MEDPin);


    GPIO_IF_GetPortNPin(GPIO_FAN_HIGH,
                      &g_uiFAN_HIGHPort,
                      &g_ucFAN_HIGHPin);

}

void //PIN TYPES: 6 - COMPRESSOR, 7 - FAN_LOW, 25 - FAN_MED, 15 - FAN_HIGH
set_GPIO_High(int pinNumber) {
	switch(pinNumber) {
		case 6:
		{
			GPIO_IF_Set(GPIO_COMPRESSOR, g_uiCOMPRESSORPort, g_ucCOMPRESSORPin, 1); // Turns on compressor
		}
		case 7:
		{
			GPIO_IF_Set(GPIO_FAN_LOW, g_uiFAN_LOWPort, g_ucFAN_LOWPin, 1); // Turns on fan low
		}
		case 25:
		{
			GPIO_IF_Set(GPIO_FAN_MED, g_uiFAN_MEDPort, g_ucFAN_MEDPin, 1); // Turns on fan med
		}
		case 15:
		{
			GPIO_IF_Set(GPIO_FAN_HIGH, g_uiFAN_HIGHPort, g_ucFAN_HIGHPin, 1); // Turns on fan high
		}
		default:
			break;
	}
}

void  //PIN TYPES: 6 - COMPRESSOR, 7 - FAN_LOW, 25 - FAN_MED, 15 - FAN_HIGH
set_GPIO_Low(int pinNumber) {
	switch(pinNumber) {
		case 6:
		{
			GPIO_IF_Set(GPIO_COMPRESSOR, g_uiCOMPRESSORPort, g_ucCOMPRESSORPin, 0); // Turns on compressor
		}
		case 7:
		{
			GPIO_IF_Set(GPIO_FAN_LOW, g_uiFAN_LOWPort, g_ucFAN_LOWPin, 0); // Turns on fan low
		}
		case 25:
		{
			GPIO_IF_Set(GPIO_FAN_MED, g_uiFAN_MEDPort, g_ucFAN_MEDPin, 0); // Turns on fan med
		}
		case 15:
		{
			GPIO_IF_Set(GPIO_FAN_HIGH, g_uiFAN_HIGHPort, g_ucFAN_HIGHPin, 0); // Turns on fan high
		}
		default:
			break;
	}
}




