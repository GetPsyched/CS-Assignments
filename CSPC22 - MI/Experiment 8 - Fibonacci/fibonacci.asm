; WAP to print the Fibonacci series upto 233

.data
a DB "Enter the number of terms: $"

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

    MOV BH, AL
    MOV AH, 01h
    INT 21h
    MOV AH, BH
    SUB AX, 3030h
    AAD
    MOV BH, AL
    MOV DL, 32
    MOV AH, 02h
    INT 21h
    MOV DL, 48
    MOV AH, 02h
    INT 21h
    MOV DL, 32
    MOV AH, 02h
    INT 21h
    MOV DL, 49
    MOV AH, 02h
    INT 21h
    DEC BH
    DEC BH
    MOV CX, 01
    MOV SI, 00
    l:MOV DI, CX
    ADD CX, SI
    MOV SI, DI
    MOV AX, CX
    MOV DI, 10
    MOV BL, 0
    m:MOV DX, 0
    DIV DI
    ADD DX, 48
    PUSH DX
    INC BL
    CMP AX, 0
    JNE m
    MOV DL, 32
    MOV AH, 02h
    INT 21h
    p:POP DX
    MOV AH, 02h
    INT 21h
    DEC BL
    CMP BL, 0
    JNE p
    DEC BH
    CMP BH, 0
    JNE l
END start
