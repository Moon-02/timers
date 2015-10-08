/*
 * @brief A program for the EA NXP LPC4088QSB to flash LED1, LED2, LED3 and LED4.
 *        LEDs are controlled by the joystick. LEFT -> LED1, DOWN -> LED2,
 *        UP -> LED3, RIGHT -> LED4, CENTER -> All LEDs
 *        This program uses a small, simple library of GPIO functions, and the 
 *        SysTick timer to control several soft timers.
 * @author David Kendall
 * @date August 2015
 */

#include "timer.h"
#include <stdint.h>
#include <stdbool.h>
#include <LPC407x_8x_177x_8x.h>
#include "led.h"

void delay(uint32_t ms);
void sysTickHandler(void);
void led12Task(void);
void led34Task(void);
void buttonsTask(void);

static softTimer_t timer[3];


void ledaction(void);
int main() {
	led_Init();
	
	timer0Init(2, ledaction);

	while (true) {
	}
}

void ledaction(void) {
	ledToggle(left_green);
}

