; WAP to find the factorial of a given number

.STACK 100h
.data
a DB "Enter the number: $"
b DB "Factorial of the number $"

.code
start:
    MOV AX, @data
    MOV DS, AX

    ; Input
    MOV DX, OFFSET a
    MOV AH, 09h
    INT 21h
    MOV AH, 01h
    INT 21h

    SUB AL, 30h
    MOV CH, 0
    MOV CL, AL
    MOV AX, 1

    l:MUL CX
    DEC CX
    CMP CX, 0
    JNE l
    MOV BX, 10
    MOV CL, 0
    m:MOV DX, 0
    DIV BX
    PUSH DX
    INC CL
    CMP AX, 0
    JNE m
    n:POP DX
    ADD DX, 30h
    MOV AH, 02h
    INT 21h
    DEC CL
    CMP CL, 0
    JNE n

    ; Print result
    MOV DX, OFFSET b
    MOV AH, 09h
    INT 21h
END start
