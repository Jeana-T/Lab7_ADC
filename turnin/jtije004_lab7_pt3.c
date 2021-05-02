/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: https://drive.google.com/file/d/1_mj60qms9Cl_XkNmwHOy7ekRqrR0mbLb/view?usp=sharing
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
	DDRD = 0xFF; PORTD = 0X00;
	ADC_init();

        while (1) {
		unsigned short my_short = ADC;
		unsigned MAX = 0xC6;

		if (my_short < (MAX/2)) {
			PORTB = 0x00;
		}
		else {
			PORTB = 0x01;
		}
        }
        return 1;

}
