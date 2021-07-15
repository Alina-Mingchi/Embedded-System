#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) 
{
    DDRB |=(1 << PB1)|(1<<PB2)|(1<<PB3); 				// set output ports
    TCCR1A |= (1 << COM1A1) | (1 << WGM10) | (1<<COM1B1); 	//set the bits for Fast PWM
    TCCR1B |= (1 << CS10)  | (1<< WGM12);				//no prescaler
    TCCR2A = 0b10000011;						//set the bits for Fast PWM 
    TCCR2B = 0b00000001;						//no prescaler
       				 // Setup ADC
    ADMUX = (1 << REFS0) | (1<<ADLAR);  				// select ADC0
    ADCSRA |=  (1 << ADPS0) | (1 << ADPS1) | (1<< ADPS2) ; 		// set division 128
    ADCSRA |= (1 << ADIE); 						//set Free Running mode
    ADCSRA |= (1 << ADEN) | (1 << ADSC); 				// enable conversion and start
    
    sei();    
    for (;;) {  } 								//infinite loop
    return 0;
}

ISR(ADC_vect) 
{
    OCR1A=ADCH; 					//set the high part of the ADC register to PB1
    OCR1B=ADCH;					//set the high part of the ADC register to PB2
    OCR2A=ADCH;					//set the high part of the ADC register to PB3
    ADCSRA |= (1 << ADSC); 						//start again
}
