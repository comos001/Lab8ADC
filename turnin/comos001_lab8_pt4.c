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

//Videolink: https://drive.google.com/open?id=1K6WX_jBlWeqJBbuAQuV8Oc2zsVoVbqPZ
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
   unsigned char max = 0xFC;
  //unsigned char min = 0x17;
   PINA = PINA & 0x01; 
     /* Insert your solution below */
   	
    while (1) {
 	x = ADC;
	if (x < (max/8)){
		PORTB = 0x00;
	}
	else if (x < (2*(max/8))){
		PORTB = 0x01;
	}
	else if (x < (3*(max/8))){
                PORTB = 0x03;
	}
	else if (x <(4*(max/8))){
                PORTB = 0x07;
        }
	else if (x <(5*(max/8))){
                PORTB = 0x1F;
        }
	else if (x <(6*(max/8))){
                PORTB = 0x3F;
        }
 	else if (x <(7*(max/8))){
                PORTB = 0x7F;
        }
	else if (x >= max){
		PORTB = 0xFF;
	}
	//PORTB = (char)x;
	//PORTD = (x >> 8);
    }
    return 1;
}
