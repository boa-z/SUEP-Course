ORG 000H
AJMP START
ORG 000BH
AJMP TIME
ORG 0030H

START:
    MOV SP, #60H
    MOV TMOD, #01H ; Set timer 0 mode 1 (16-bit timer)
    MOV TH0, #3CBH ; 修改定时器初值，以实现50ms定时
    MOV TL0, #0F3H ; 修改定时器初值，以实现50ms定时
    MOV R0, #0AH
    MOV R1, #14H ; 增加计数器20
    SETB ET0 ; Enable timer 0 interrupt
    SETB EA ; Enable global interrupts
    SETB TR0 ; Start timer 0

LOOP: AJMP LOOP

TIME:
    CLR TR0 ; Stop timer 0
    CLR TF0 ; Clear timer 0 overflow flag
    DJNZ R0, NOT_05S ; 计数器10减1，若不为零则跳转到NOT_05S标签处执行
    MOV R0, #0AH ; 计数器10重新赋值为10
    CPL P0.0
NOT_05S:
    DJNZ R1, NOT_10S ; 计数器20减1，若不为零则跳转到NOT_10S标签处执行
    MOV R1, #14H ; 计数器20重新赋值为20
    CPL P0.1
NOT_10S:
    MOV TH0, #3CBH ; Set timer 0 initial value for next period
    MOV TL0, #0F3H ; Set timer 0 initial value for next period
    SETB TR0 ; Start timer 0 for next period
    RETI
END