; WAP to divide 2 8-bit single-digit numbers

.data
a db "Enter the first number:$"
b db "Enter the second number:$"
c db "Division is:$"

.code
start:
    MOV AX, @data
    MOV DS, AX

    ; Input
    MOV DX, OFFSET A
    MOV AH, 09H
    INT 21H
    MOV AH, 01H
    INT 21H

    SUB AL, 30H
    MOV BL, AL

    ; Input
    MOV DX, OFFSET B
    MOV AH, 09H
    INT 21H
    MOV AH, 01H
    INT 21H

    SUB AL, 30H
    MOV CL, AL
    MOV AL, BL
    MOV AH, 0
    DIV CL
    MOV BX, AX
    ADD BX, 3030H

    ; Print string
    MOV DX, OFFSET C
    MOV AH, 09H
    INT 21H

    ; Print value
    MOV DL, BH
    MOV AH, 02H
    INT 21H
    MOV DL, BL
    MOV AH, 02H
    INT 21H
END start
