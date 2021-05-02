/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7 Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *Demo Link: https://drive.google.com/file/d/1gBICVZuNK8f5WqGbMwf7gwkLc47zYQkH/view?usp=sharing
 *
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include <avr/interrupt.h>
#include "simAVRHeader.h"
#endif

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    	DDRA = 0x00; PORTA = 0xFF;
        DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	unsigned short my_short = 0x00;
	unsigned char my_charB = 0x00;
	unsigned char my_charD = 0x00;
	ADC_init();

        while (1) {
		my_short = ADC;

		my_charB = (char)my_short & 0xFF;
		PORTB = my_charB;

		my_charD  = my_short >> 8;
		PORTD = my_charD; 
        }
        return 1;

}
