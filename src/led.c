/* LED Device Driver file:
   Device drivers for the LEDs
	 Dr Alun Moon
	 06/10/2015
*/
#include <LPC407x_8x_177x_8x.h>
#include <stdint.h>
#include "led.h"

#define LED1PIN    (1UL << 18)
#define LED2PIN    (1UL << 13)
#define LED3PIN    (1UL << 13)
#define LED4PIN    (1UL << 19)

#define nil 0

/* function to initialise the LED gpio regiters */
void led_Init(void){
	LPC_IOCON->P1_18 &= ~0x1FUL;
	LPC_IOCON->P0_13 &= ~0x1FUL;
	LPC_IOCON->P1_13 &= ~0x1FUL;
	LPC_IOCON->P2_19 &= ~0x1FUL;

	/* all GPIO pins are outputs */
	LPC_GPIO1->DIR |= LED1PIN;
	LPC_GPIO0->DIR |= LED2PIN;
	LPC_GPIO1->DIR |= LED3PIN;
	LPC_GPIO2->DIR |= LED4PIN;
	
	/* make sure LEDs start off */
	LPC_GPIO1->SET = LED1PIN;
	LPC_GPIO0->SET = LED2PIN;
	LPC_GPIO1->CLR = LED3PIN;
	LPC_GPIO2->CLR = LED4PIN;

}

/* functions to set the state of the LEDs */
void ledOn    (enum LED name){
	switch(name) {
		case LED1:
			LPC_GPIO1->CLR = LED1PIN;
			break;
		case LED2:
			LPC_GPIO0->CLR = LED2PIN;
			break;
		case LED3:
			LPC_GPIO1->SET = LED3PIN;
			break;
		case LED4:
			LPC_GPIO2->SET = LED4PIN;
			break;
	}
}

void ledOff   (enum LED name){
	switch(name) {
		case LED1:
			LPC_GPIO1->SET = LED1PIN;
			break;
		case LED2:
			LPC_GPIO0->SET = LED2PIN;
			break;
		case LED3:
			LPC_GPIO1->CLR = LED3PIN;
			break;
		case LED4:
			LPC_GPIO2->CLR = LED4PIN;
			break;
	}
}

void ledToggle(enum LED name){
	switch(name) {
		case LED1:
			LPC_GPIO1->MASK = ~LED1PIN;
			LPC_GPIO1->PIN ^= LED1PIN;
			LPC_GPIO1->MASK = nil;
			break;
		case LED2:
			LPC_GPIO0->MASK = ~LED2PIN;
			LPC_GPIO0->PIN ^= LED2PIN;
			LPC_GPIO0->MASK = nil;
			break;
		case LED3:
			LPC_GPIO1->MASK = ~LED3PIN;
			LPC_GPIO1->PIN ^= LED3PIN;
			LPC_GPIO1->MASK = nil;
			break;
		case LED4:
			LPC_GPIO2->MASK = ~LED4PIN;
			LPC_GPIO2->PIN ^= LED4PIN;
			LPC_GPIO2->MASK = nil;
			break;
	}

}

/* find the state of an LED */
int  ledState (enum LED name){
	int state = 0;
	switch(name) {
		case LED1:
			LPC_GPIO1->MASK = ~LED1PIN;
			state = LPC_GPIO1->PIN;
			LPC_GPIO1->MASK = nil;
			break;
		case LED2:
			LPC_GPIO0->MASK = ~LED2PIN;
			state = LPC_GPIO0->PIN;
			LPC_GPIO0->MASK = nil;
			break;
		case LED3:
			LPC_GPIO1->MASK = ~LED3PIN;
			state = LPC_GPIO1->PIN;
			LPC_GPIO1->MASK = nil;
			break;
		case LED4:
			LPC_GPIO2->MASK = ~LED4PIN;
			state = LPC_GPIO2->PIN;
			LPC_GPIO2->MASK = nil;
			break;
	}
	return state;
}

