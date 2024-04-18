; WAP to find if an 8-bit number is odd or even

.data
MSG1 DW "ENTER A NUMBER:$"
MSG2 DW "NUMBER IS EVEN$"
MSG3 DW "NUMBER IS ODD$"

.code
START:
    MOV AX, @data
    MOV DS, AX

    MOV DX, OFFSET MSG1
    MOV AH, 09H
    INT 21H

    MOV AH, 01H
    INT 21H

    MOV DX, 0H
    MOV BX, 02H
    DIV BX
    CMP DX, 0H
    JNZ LABEL
    ;PRINT EVEN
    MOV DX, OFFSET MSG2
    MOV AH, 09H
    INT 21H
    HLT

LABEL:
    ;ODD
    MOV DX, OFFSET MSG3
    MOV AH, 09H
    INT 21H
    END START
