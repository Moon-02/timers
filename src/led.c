/* LED Device Driver file:
   Device drivers for the LEDs
	 Dr Alun Moon
	 06/10/2015
*/
#include <LPC407x_8x_177x_8x.h>
#include <stdint.h>
#include "led.h"

#define led1pin    (1UL << 18)
#define led2pin    (1UL << 13)
#define led3pin    (1UL << 13)
#define led4pin    (1UL << 19)
#define ledRpin    (1UL << 11)
#define ledGpin		 (1UL <<  5)
#define ledBpin    (1UL <<  7)
#define nil 0

/* function to initialise the LED gpio regiters */
void led_Init(void){
	LPC_IOCON->P1_18 &= ~0x1FUL;
	LPC_IOCON->P0_13 &= ~0x1FUL;
	LPC_IOCON->P1_13 &= ~0x1FUL;
	LPC_IOCON->P2_19 &= ~0x1FUL;
  LPC_IOCON->P1_11 &= ~0x1FUL;
  LPC_IOCON->P1_5 &= ~0x1FUL;
  LPC_IOCON->P1_7 &= ~0x1FUL;

	/* all GPIO pins are outputs */
	LPC_GPIO1->DIR |= led1pin;
	LPC_GPIO0->DIR |= led2pin;
	LPC_GPIO1->DIR |= led3pin;
	LPC_GPIO2->DIR |= led4pin;
	LPC_GPIO1->DIR |= ledRpin;
	LPC_GPIO1->DIR |= ledGpin;
	LPC_GPIO1->DIR |= ledBpin;
	
	/* make sure LEDs start off */
	LPC_GPIO1->SET = led1pin;
	LPC_GPIO0->SET = led2pin;
	LPC_GPIO1->CLR = led3pin;
	LPC_GPIO2->CLR = led4pin;
	LPC_GPIO1->SET = ledRpin;
	LPC_GPIO1->SET = ledGpin;
	LPC_GPIO1->SET = ledBpin;

}

/* functions to set the state of the LEDs */
void ledOn    (enum LED name){
	switch(name) {
		case LED1:
			LPC_GPIO1->CLR = led1pin;
			break;
		case LED2:
			LPC_GPIO0->CLR = led2pin;
			break;
		case LED3:
			LPC_GPIO1->SET = led3pin;
			break;
		case LED4:
			LPC_GPIO2->SET = led4pin;
			break;
		case BBLED1R:
			LPC_GPIO1->CLR = ledRpin;
			break;
		case BBLED1G:
			LPC_GPIO1->CLR = ledGpin;
			break;
		case BBLED1B:
			LPC_GPIO1->CLR = ledBpin;
			break;
	}
}

void ledOff   (enum LED name){
	switch(name) {
		case LED1:
			LPC_GPIO1->SET = led1pin;
			break;
		case LED2:
			LPC_GPIO0->SET = led2pin;
			break;
		case LED3:
			LPC_GPIO1->CLR = led3pin;
			break;
		case LED4:
			LPC_GPIO2->CLR = led4pin;
			break;
		case BBLED1R:
			LPC_GPIO1->SET = ledRpin;
			break;
		case BBLED1G:
			LPC_GPIO1->SET = ledGpin;
			break;
		case BBLED1B:
			LPC_GPIO1->SET = ledBpin;
			break;
	}
}

void ledToggle(enum LED name){
	switch(name) {
		case LED1:
			LPC_GPIO1->MASK = ~led1pin;
			LPC_GPIO1->PIN ^= led1pin;
			LPC_GPIO1->MASK = nil;
			break;
		case LED2:
			LPC_GPIO0->MASK = ~led2pin;
			LPC_GPIO0->PIN ^= led2pin;
			LPC_GPIO0->MASK = nil;
			break;
		case LED3:
			LPC_GPIO1->MASK = ~led3pin;
			LPC_GPIO1->PIN ^= led3pin;
			LPC_GPIO1->MASK = nil;
			break;
		case LED4:
			LPC_GPIO2->MASK = ~led4pin;
			LPC_GPIO2->PIN ^= led4pin;
			LPC_GPIO2->MASK = nil;
			break;
		case BBLED1R:
			LPC_GPIO1->MASK = ~ledRpin;
			LPC_GPIO1->PIN ^= ledRpin;
			LPC_GPIO1->MASK = nil;
			break;
		case BBLED1G:
			LPC_GPIO1->MASK = ~ledGpin;
			LPC_GPIO1->PIN ^= ledGpin;
			LPC_GPIO1->MASK = nil;
			break;
		case BBLED1B:
			LPC_GPIO1->MASK = ~ledBpin;
			LPC_GPIO1->PIN ^= ledBpin;
			LPC_GPIO1->MASK = nil;
			break;
	}

}

/* find the state of an LED */
int  ledState (enum LED name){
	int state = 0;
	switch(name) {
		case LED1:
			LPC_GPIO1->MASK = ~led1pin;
			state = LPC_GPIO1->PIN;
			LPC_GPIO1->MASK = nil;
			break;
		case LED2:
			LPC_GPIO0->MASK = ~led2pin;
			state = LPC_GPIO0->PIN;
			LPC_GPIO0->MASK = nil;
			break;
		case LED3:
			LPC_GPIO1->MASK = ~led3pin;
			state = LPC_GPIO1->PIN;
			LPC_GPIO1->MASK = nil;
			break;
		case LED4:
			LPC_GPIO2->MASK = ~led4pin;
			state = LPC_GPIO2->PIN;
			LPC_GPIO2->MASK = nil;
			break;
		case BBLED1R:
			LPC_GPIO2->MASK = ~ledRpin;
			state = LPC_GPIO2->PIN;
			LPC_GPIO2->MASK = nil;
			break;
		case BBLED1G:
			LPC_GPIO2->MASK = ~ledGpin;
			state = LPC_GPIO2->PIN;
			LPC_GPIO2->MASK = nil;
			break;
		case BBLED1B:
			LPC_GPIO2->MASK = ~ledBpin;
			state = LPC_GPIO2->PIN;
			LPC_GPIO2->MASK = nil;
			break;
	}
	return state;
}

