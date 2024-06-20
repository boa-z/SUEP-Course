ORG 0000H
AJMP MAIN
ORG 0030H
MAIN: MOV P0, #00H
      MOV P1, #00H
      MOV P2, #00H
      MOV P3, #08H
WAIT: JNB P3.3, WAIT
      ACALL DELAY
      JNB P3.3, WAIT
      MOV R0, #01H
LOOP: MOV A, R0
      MOV P0, A
      ACALL DELAY
      RR A
      RR A
      RR A
      RR A
      RR A
      RR A
      RR A
      MOV R0, A
      SJMP LOOP

DELAY: MOV R2, #0FFH
AGAIN: DJNZ R2, AGAIN
       RET

END