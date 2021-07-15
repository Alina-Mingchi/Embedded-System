#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
 
int main(void) 
{
    DDRD = 0xFF; 					//set output port
    PORTD = 0x00;
    							// Setup ADC
    ADMUX = (1 << REFS0) | (1<<ADLAR);  		//select ADC0
    ADCSRA |=  (1 << ADPS0) | (1 << ADPS1) ; 	// choose proper prescaling
    ADCSRA |= (1 << ADIE) | (1 << ADATE); 		//set Free Running mode
    ADCSRA |= (1 << ADEN) | (1 << ADSC); 		// enable the conversion and start
  
    sei();							//enable interrupts
    for (;;) { }						//infinite loop
    return 0;
}

ISR(ADC_vect) 
{
    PORTD=ADCH; 					//set the high part of the ADC register to PORTD
    ADCSRA |= (1 << ADSC);				//start again
}
