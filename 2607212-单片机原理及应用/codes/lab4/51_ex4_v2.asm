ORG 0000H
SJMP START
ORG 0030H
 
START: MOV P0,#0FFH
 
AJ:  JB P3.2,AJ
         LCALL DELAY
         JB P3.2,AJ
 
LOOP: SETB P2.2
		MOV P0,#0E7H
           LCALL DELAY
          MOV P0,#0DBH
         LCALL DELAY
          MOV P0,#0BDH
          LCALL DELAY
          MOV P0,#7EH
         LCALL DELAY
         AJMP LOOP
 
DELAY: MOV R6,#0FEH
LOOP2: MOV R7,#00H
LOOP1: DJNZ R7,LOOP1
            DJNZ R6,LOOP2
            RET 
            END