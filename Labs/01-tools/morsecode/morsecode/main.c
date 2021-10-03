#define LED_GREEN   PB5 // AVR pin where green LED is connected
#define SHORT_DELAY 400 // Delay in milliseconds
#define LONG_DELAY 1000

#include <util/delay.h> // Functions for busy-wait delay loops
#include <avr/io.h>     // AVR device-specific IO definitions

int main(void)
{
	// Set pin as output in Data Direction Register
	// DDRB = DDRB or 0010 0000
	DDRB = DDRB | (1<<LED_GREEN);

	// Set pin LOW in Data Register (LED off)
	// PORTB = PORTB and 1101 1111
	PORTB = PORTB & ~(1<<LED_GREEN);

	// Infinite loop
	while (1)
	{
		// Pause several milliseconds
		_delay_ms(SHORT_DELAY);
		PORTB = PORTB & ~(1<<LED_GREEN); // Light on
		_delay_ms(SHORT_DELAY);
		PORTB = PORTB & ~(1<<LED_GREEN); // Light off
		_delay_ms(SHORT_DELAY);
		PORTB = PORTB & ~(1<<LED_GREEN); // Light on
		_delay_ms(LONG_DELAY);
		PORTB = PORTB & ~(1<<LED_GREEN); // Light off

		// WRITE YOUR CODE HERE
	}

	// Will never reach this
	return 0;
}