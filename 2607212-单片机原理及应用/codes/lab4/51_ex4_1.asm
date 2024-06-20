ORG 000H
AJMP START
ORG 000BH
AJMP TIME
ORG 0030H

START:
    MOV SP, #60H
    MOV TMOD, #01H ; Set timer 0 mode 1 (16-bit timer)
    MOV TH0, #03CH ; Set timer 0 initial value
    MOV TL0, #0B0H ; Set timer 0 initial value
    MOV R0, #0AH
    SETB ET0 ; Enable timer 0 interrupt
    SETB EA ; Enable global interrupts
    SETB TR0 ; Start timer 0
LOOP: AJMP LOOP

TIME:
    CLR TR0 ; Stop timer 0
    CLR TF0 ; Clear timer 0 overflow flag
    CPL P1.0 ; Toggle P1.0 port
    MOV TH0, #3CH ; Set timer 0 initial value for next period
    MOV TL0, #0B0H ; Set timer 0 initial value for next period
    SETB TR0 ; Start timer 0 for next period
    RETI
END