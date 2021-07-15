#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
 
#This is to blink the LED 1 second by output compare interrupt. 
int main(void)
{
    cli();                              	//disable the interrupts
    OCR1A=15625;    		//Set the value that timer compares
    TCCR1B =0b00001101; 	//set bits for TCCR1B register 
    TIMSK1 =0b00000010; 	//set bits for the mask
    sei();				//enable the interrupts    
    DDRD=0xFF;		//set output pin
   
    while(1){  }
}
 
ISR(TIMER1_COMPA_vect)
{
    PORTD^=0xFF;     		//toggle
    OCR1A=15625;    		//set the value that timer compares again
}



#frequency of the LED is changed continuously
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
 
int i=100;			
 
int main(void)
{
    cli();                              	//disable interrupts
    OCR1A=200; 		//set the initial value
    TCCR1B =0b00001001; 	//set the bits for TCCR1B
    TIMSK1 =0b00000010; 	//set the mask
    sei();				//enable interrupt   
    DDRD=0xFF; 		//set output port
   
    while(1)
    {  
   	 PORTD=0xFF;	//set value for PORTD
    }
}
 
ISR(TIMER1_COMPA_vect)
{   
    PORTD=0x00; 		//set value for PORTD
    if(OCR1A==65400 || OCR1A==100)
    {
        i=-i;			//flipping the value
    }				
    OCR1A=OCR1A+i; 	// changing the value
    _delay_ms(1); 		//set delay
}





#fast PWM mode
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <util/delay.h>
 
int main (void) 
{
    DDRB |=(1 << PB1); 				// set the output
    TCCR1A |= (1 << COM1A1) | (1 << WGM10) ;	//set the bits for pin OC1A
    TCCR1B |= (1 << CS10)  | (1<< WGM12);		//set the bits
    uint8_t pwm = 0x00; 				//value to output
    bool up = true;
    for(;;) { 						// infinite loop
        OCR1A = pwm;
        pwm += up ? 1 : -1; 				// if true add 1, if not minus 1
        if (pwm == 0xff)    				//if maximum
            up = false;    
        else if (pwm == 0x00)  				//if minimum
            up = true;         
        _delay_ms(10);      				//delay
    }
}
