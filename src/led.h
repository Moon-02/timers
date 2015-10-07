/* LED header file:
   constants and functions making up the driver API for the LEDs

	 Dr Alun Moon
	 06/10/2015
*/

enum LED {
	/* PCB names */
	LED1, LED2, LED3, LED4,
	/* logical names */
	left_green=LED1, right_green,
	left_blue,	right_blue
};

/* function to initialise the LED gpio regiters */
void led_Init(void);


/* functions to set the state of the LEDs */
void ledOn    (enum LED name);
void ledOff   (enum LED name);
void ledToggle(enum LED name);

/* find the state of an LED */
int  ledState (enum LED name);
