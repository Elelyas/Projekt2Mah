/*
*Main file of the project-.
*Author: Elias Hussein
*/

//	Inkluderar bibiloteken.
#include <asf.h>
#include <stdio.h>
#include "task.h"
#include <ioport.h>
#include "FreeRTOSConfig.h"
#include "delay.h"
#include "task_LED.h"
#include "task_BLINKA.h"
#include "task_VinkelGivare.h"


//	Definierar pinnar som jag använder.
#define LED PIO_PB27_IDX
#define Blinkared PIO_PB26_IDX
#define Blinkayellow PIO_PA14_IDX

int main (void)
{
	// Initialisera Due kortet */
	sysclk_init();
	board_init();
	ioport_init();
	delayInit();
	
	// Sätter direction för pinnar, Utgångar / Ingångar.
	ioport_set_pin_dir(Blinkared,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(Blinkayellow,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(LED,IOPORT_DIR_OUTPUT);
	
	//Skapar tasken nedan.
	//Task med högst prioritet
	if (xTaskCreate(task_VinkelGivare, (const signed char * const) "VinkelGivare", TASK_VINKELGIVARE_STACK_SIZE, NULL, TASK_VINKELGIVARE_STACK_PRIORITY, NULL) != pdPASS) {
		printf("Failed the VinkelGivare Task\r\n");
	}
	
	//Task med näst högst prioritet
	if (xTaskCreate(task_LED, (const signed char * const) "LED", TASK_LED_STACK_SIZE, NULL, TASK_LED_STACK_PRIORITY, NULL) != pdPASS) {
		printf("Failed the LED Task\r\n");
	}
	
	//Task med lägst prioritet
	if (xTaskCreate(task_BLINKA, (const signed char * const) "BLINKA", TASK_BLINKA_STACK_SIZE, NULL, TASK_BLINKA_STACK_PRIORITY, NULL) != pdPASS) {
		printf("Failed the BLINKA Task\r\n");
	}
	
	//Ser till att köra tasken.
	vTaskStartScheduler();
}
