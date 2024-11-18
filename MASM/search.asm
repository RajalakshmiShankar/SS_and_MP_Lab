ASSUME CS:CODE, DS:DATA

PRINT MACRO MSG
LEA DX, MSG
MOV AH, 09H
INT 21H
ENDM

DATA SEGMENT
	ARRAY DW 1234H, 2345H, 3456H, 4567H, 5678H
	LEN EQU 05H
	KEY DW 1234H
	STR1 DB 'KEY FOUND$'
	STR2 DB 'KEY NOT FOUND$'
DATA ENDS
CODE SEGMENT
START:
	MOV AX, DATA
	MOV DS, AX

	LEA SI, ARRAY
	
	MOV CX, LEN
	MOV BX, KEY
	
NEXT: 	
	MOV AX, [SI]
	CMP AX, BX
	JZ FOUND
	
	INC SI 
	INC SI
	
	DEC CX
	
	JNZ NEXT

	PRINT STR2
	JMP EXIT

FOUND: 	PRINT STR1

EXIT: 	MOV AH, 4CH
	INT 21H

CODE ENDS
END START