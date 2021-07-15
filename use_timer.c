#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
 
int main(void)
{
	cli();                                   		   //disable interrupts
	 TCNT1 = 49911;                                  //set the value 
	TCCR1B = 0b00001101;               	  //set bits for TCCR1B register
	CLK/1024				  //prescaler
            TIMSK1 = 0x01;                   		  //enable timer interrupt
	sei();                           			  //enable interrupts
	DDRB=(1<<PORTB0);                
      
	while(1)
	{}
}
 
ISR(TIMER1_OVF_vect)			//Timer Overflow Interrupt
{
            PORTB^=0xFF;              
	TCNT1 = 49911;            
}
