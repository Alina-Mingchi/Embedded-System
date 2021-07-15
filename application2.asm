/* lab2mme.asm
 *
 *  Created: 9/17/2018 2:23:57 PM
 *   Author: Micro_Lab
 */ 
 .include "m328def.inc"

 .org 0x0000
           JMP Begin;
 .org 0x0002
           JMP Inter;       	 	Based on the address we found in data sheet

 .org 0x0034

 Begin: LDI R16, low(RAMEND)
            OUT SPL, R16
       	    LDI R16, high(RAMEND)
            OUT SPH, R16
            LDI  R16, 0xF0
            OUT DDRD, R16
            LDI R16, 0x00;           Checks low 
            STS EICRA, R16;      To access interrupt register
            LDI R16, 0x01
            OUT EIMSK, R16;      We set the mask
            SEI	;        			  All needed for interrupt are set

        

Main:   LDI R16, 0X00
           OUT PORTD, R16
           RCALL Delay;              Same as we did in Lab1, delay blinking
           LDI R16, 0xFF
           OUT PORTD, R16
           RCALL Delay
           JMP Main; 		 Program goes endless

Inter:  LDI R16, 0x00
          OUT PORTD, R16
          RCALL Delay3;        	Delay blinking when interrupt is activated
          LDI R16, 0xFF
          OUT PORTD, R16
          RCALL Delay3
          RETI;			 Denoted end of interrupt routine
Delay:  LDI R18, 255
Loop:   RCALL Delay1;		Go to the next delay function
            DEC R18
            BRNE Loop
            RET

Delay1: LDI R19, 255
Loop1:  RCALL Delay2	;	Go to the next delay function
            DEC R19
            BRNE Loop1
            RET

Delay2: LDI R20, 82
Loop2:  DEC R20
             BRNE Loop2
             RET;			Three delays for 1 second

Delay3: LDI R21, 255
Loop3:  RCALL Delay4;	Go to the next delay function
             DEC R21
             BRNE Loop3
             RET

Delay4: LDI R22, 255
Loop4:  RCALL Delay7;	Go to the next delay function
             DEC R22
             BRNE Loop4
             RET

Delay7: LDI R25, 255
Loop7:  DEC R25
             BRNE Loop7
             RET;			Three delays for about 3 seconds
