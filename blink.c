/*
 * lab3blink.c
 *
 * Created: 9/18/2018 2:26:45 PM
 *  Author: Micro_Lab
 */ 

 #include <avr/io.h>
 #define F_CPU 20000000UL  //frequency of cpu is 20 MHz
 #include <util/delay.h>
 #include <avr/interrupt.h>

 int main(void)

 {
     cli();		//disable the interrupt

     DDRB = (1<<PORTB0)|(1<<PORTB1)|(1<<PORTB2);  //set LEDs as inputs

     EIMSK=(1<<INT1);

     sei();		//enable the interrupt

     while (1)
     {
         PORTB=(1<<PORTB0);

         _delay_ms(500);		//blink

         PORTB^=(1<<PORTB0);

         _delay_ms(500);		//wait

         PORTB=(1<<PORTB1);

         _delay_ms(500);		//blink

         PORTB^=(1<<PORTB1);

         _delay_ms(500);		//wait

         PORTB=(1<<PORTB2);

         _delay_ms(500);		//blink

         PORTB^=(1<<PORTB2);

         _delay_ms(500);		//wait
     }

 }

//The interrupt service routine

 ISR(INT1_vect) 	

 {
     PORTB=((1<<PORTB0)|(1<<PORTB1)|(1<<PORTB2));

     _delay_ms(500);			//blink

     for(int i=0;i<5;i++)
     {
         PORTB^=((1<<PORTB0)|(1<<PORTB1)|(1<<PORTB2));

         _delay_ms(500);		//wait
     }
 }

