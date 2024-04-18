; WAP to subtract 2 8-bit single-digit numbers

.data
a DB "Enter the first number:$"
b DB "Enter the second number:$"
c DB "Difference is:$"

.code
start:
    MOV AX, data
    MOV DS, AX

    ; Input
    MOV DX, OFFSET a
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
    SUB AL, CL
    MOV AH, 0
    AAS
    MOV BL, AL
    ADD BL, 30H

    ; Print string
    MOV DX, OFFSET C
    MOV AH, 09H
    INT 21H

    ; Print value
    MOV DL, BL
    MOV AH, 02H
    INT 21H
END start
