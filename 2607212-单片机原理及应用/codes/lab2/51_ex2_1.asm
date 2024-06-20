ORG 0000H
AJMP MAIN
ORG 0030H
DB 30H,31H,32H,33H,34H,35H,36H,37H,38H,39H

MAIN:
    MOV R0,#60H
    MOV R1,#70H
    MOV DPTR,#0030H

    ; step2: load data from lookup table into RAM locations 60H to 69H
    MOV R2,#10
LOAD:
	CLR A
    MOVC A,@A+DPTR
    MOV @R0,A
    INC DPTR
    INC R0
    DJNZ R2,LOAD

    ; step3: copy data from RAM locations 60H to 69H to RAM locations 70H to 79H
    MOV R0,#60H
    MOV R2,#10
COPY:
    MOV A,@R0
    MOV @R1,A
    INC R0 
    INC R1
    DJNZ R2,COPY

END