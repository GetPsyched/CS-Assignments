; WAP to subtract 2 16-bit single-digit numbers

.data
num1 DW 8
num2 DW 6

.code
start:
    MOV AX, data
    MOV DS, AX

    MOV AX, num1
    SUB AX, num2 ; Subtracting num2 from num1

	MOV DL, AL
	ADD DL, 48
	MOV AH, 02
	INT 21h

END start
