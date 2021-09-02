/*
 * ATTimer0.c
 *
 * Created: 1/09/2021 8:34:23 p. m.
 * Author : Mateo Quintero Hernández
 */ 

/* 
	In the main code, the ISR must be written
	to process the timer0 overflow interrupt
	
	The time for TCNT0 overflow is T_overflow = 1/(CLK_I/O / PRESCALER / 255)
	the number of times the TCNT0 must overflow is ( desired_time / T_overflow )
*/
#include <avr/io.h>
#include <avr/interrupt.h>

#define CLK_IO 1000000 // Using internal clock of 1MHz - defined in ATTimer0_config
#define PRESCALER 1024 // Using a prescaler of 1024 - defined in ATTimer0_config
int volatile count; // number of times that the timer must overflow, use this in ISR

/* Replace with your library code */
void ATTimer0_config(int time) // time is any time in seconds
{
	count = time / ( 1 / (CLK_IO / PRESCALER / 255) ); 
	TCCR0A = 0x00; // Normal mode for Timer0
	sei(); // Enable global interrupts
	TCNT0=0; // Clear timer register
	TIMSK |= (1 << TOIE0); // Enable Timer 0 interrupt flag
}

void ATTimer_init()
{
	TCCR0B |= (1 << CS02) & (0 << CS01) & (1 << CS00) // Start counter - internal clock - 1024 prescaler
}

void ATTimer_stop()
{
	TCCR0B |= (0 << CS02) & (0 << CS01) & (0 << CS00)
}

void ATTimer_clear_flag()
{
	TIFR = (1 << TOV0); // Clear Timer0 interrupt flag
}


