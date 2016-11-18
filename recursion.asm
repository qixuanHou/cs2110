;;===============================
;;Name:Qixuan Hou
;;===============================

.orig x3000

	; Initialize stack
	LD R6, STACK

	LD R0, N
	ADD R6, R6, -1
	STR R0, R6, 0
	JSR POWERSOF2

	; Pop return value and arg off stack
	LDR R0, R6, 0
	ADD R6, R6, 2

	; Save the answer
	ST R0, ANSWER

	HALT

N 		.fill 5
ANSWER 	.blkw 1
STACK 	.fill xF000


POWERSOF2
	ADD R6, R6, -3		;move up stack 3 spots
	STR R7, R6, 1		;store return address
	STR R5, R6, 0		;store old frame pointer
	ADD R5, R6, -1		;create new frame pointer

	ADD R6, R6, -2		;allocate 2 locates

	AND R0, R0, 0 
	STR R0, R5, 0		;store temp1
	STR R0, R5, -1		;store temp2

	LDR R2, R5, 4		;load N
	ADD R2, R2, -1		;
	BRP ELSE		;if N!=0 && N!=1, go to else
	BRZ ONE
	BRN ZERO

ZERO	AND R2, R2, 0		
	ADD R2, R2, 1		
	STR R2, R5, 3		
	BR RETURN		
	
ONE	AND R2, R2, 0	
	ADD R2, R2, 2
	STR R2, R5, 3
	BR RETURN	

ELSE
	ADD R6, R6, -1		;allocate for argument
	STR R2, R6, 0		;pushed N-1 on stack
	JSR POWERSOF2		;

	LDR R0, R6, 0		;read return value off top of stack
	STR R0, R5, 0		;store temp1 value
	

	LDR R2, R5, 4		;load N
	ADD R2, R2, -2
	ADD R6, R6, -5		;allocate for argument 
	STR R2, R6, 0		;pushed N-2 on stack
	JSR POWERSOF2

	LDR R0, R6, 0		;read return value off top of stack
	STR R0, R5, -1		;store temp2 value 
	
	LDR R0, R5, 0		;load temp1
	LDR R1, R5, -1		;load temp2
	NOT R1, R1
	ADD R1, R1, 1

	AND R4, R4, 0	
	ADD R4, R4, R0
	ADD R4, R4, R0
	ADD R4, R4, R0
	ADD R4, R4, R1
	ADD R4, R4, R1		;3*temp1 - 2*temp2
	
	STR R4, R5, 3		;store return value

RETURN
	ADD R6, R5, 3		;now points to return value
	LDR R7, R5, 2		;restore return address
	LDR R5, R5, 1		;restore old frame pointer
	RET			;return


.end
