/*	Author: victoromosor
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

//VideoLink: https://drive.google.com/file/d/1salsVHxHX-nFUWHEmI_iK2hm7FlE_lME/view?usp=sharing
void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
} 

// MAX = 0xE3;
// MIN = 0x17;


int main(void) {
   DDRA = 0x00; PORTA = 0xFF;
   DDRB = 0xFF; PORTB = 0x00;
   DDRD = 0xFF; PORTD = 0x00;
    
   ADC_init();
   unsigned short x;
   PINA = PINA & 0x01; 
     /* Insert your solution below */
   	
    while (1) {
 	x = ADC;
	PORTB = (char)x;
	PORTD = (x >> 8);
    }
    return 1;
}
