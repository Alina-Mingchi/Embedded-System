/*
* AssemblerApplication1.asm
*
* Created: 9/10/2018 3:14:04 PM * Author: Micro Lab
*/
.include "m328def.inc"
.org 0x0000
  RJMP begin ; jump to begin
.org 0x0034
begin: CLI
  LDI R16, low(RAMEND) 
  OUT SPL, R16
  LDI R16, high(RAMEND) 
  OUT SPH, R16
  LDI R16, 0xFF
  OUT DDRD, R16
toggle: LDI R16, 0xFF ; toggle ensures that the program runs continuously 
  OUT PORTD, R16
  RCALL Delay
  LDI R16, 0x00 
  OUT PORTD, R16 
  RCALL Delay 
  RCALL toggle
Delay: LDI R17, 0xFF ; set R17 to be 255 (decimal)
loop: RCALL Delay1
  DEC R17 
  BRNE loop 
  RET
Delay1: LDI R18, 0xFF ; set R18 to be 255 (decimal)
loop1: RCALL Delay2
  DEC R18 
  BRNE loop1 
  RET
Delay2: LDI R19, 0x52 ; set R19 to be 82 (decimal)
loop2: DEC R19
  BRNE loop2
  RET
