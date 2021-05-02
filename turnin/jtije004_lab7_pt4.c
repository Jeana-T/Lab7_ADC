/*
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	DemoLink: https://drive.google.com/file/d/19t5x34T1VZCrykMhQ0FJLWq_ZkMNU2XF/view?usp=sharing
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    	DDRA = 0x00; PORTA = 0xFF;
        DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;

	ADC_init();

        while (1) {
		unsigned char output;
		unsigned short my_short = ADC;

		if (my_short >= 280) {
			output = 0xFF;
		}
		else if(my_short >= 245) {
			output = 0x7F;
		}
		else if(my_short >= 210) {
			output = 0x3F;
		}
		else if(my_short >= 175) {
			output = 0x1F;
		}
		else if(my_short >= 140) {
			output = 0x0F;
		}
		else if(my_short >= 105) {
                        output = 0x07;
                }
                else if (my_short >= 70) {
                        output = 0x03;
                }
		else if (my_short >= 35) {
			output = 0x01;
		}
		else {
			output = 0x00;
		}

		PORTB = output;
        }
        return 1;

}
