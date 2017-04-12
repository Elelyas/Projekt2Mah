/*
 * task_LED.c
 *
 * Created: 2017-04-12 22:47:02
 *  Author: Elias
 */ 
#include <asf.h>
#include "task_LED.h"

void task_LED(void *pvParameters)

#define LED PIO_PB27_IDX
{
	portTickType xLastWakeTime;
	const portTickType xTimeIncrement = 100;
	xLastWakeTime = xTaskGetTickCount(); /* Initialise the xLastWakeTime variable with the current time. */
	while (1) {
		vTaskDelayUntil(&xLastWakeTime, xTimeIncrement); /*
		Wait for the next cycle. */
		gpio_toggle_pin(LED0_GPIO); // F�r ledlampan p� kortet
		
				ioport_set_pin_level(LED,HIGH);
				delayMicroseconds(500000);
				ioport_set_pin_level(LED,LOW);
				delayMicroseconds(500000);
		
	}
	vTaskDelete( NULL );
}