; WAP to find if an 16-bit number is positive or negative

.data
MSG1 DW "ENTER A NUMBER:$"
MSG2 DW "NUMBER IS POSITIVE$"
MSG3 DW "NUMBER IS NEGATIVE$"
NUM1 DW 9925H
NUM2 DW 2851H

.code
START:
    MOV AX, @data
    MOV DS, AX
    MOV DX, OFFSET MSG1
    MOV AH, 09H
    INT 21H
    MOV AH, 01H
    INT 21H
    MOV BL, AL
    MOV AH, 01H
    INT 21H

    CMP BL, '-'
    JZ l
    ; PRINT POSITIVE
    MOV DX, OFFSET MSG2
    MOV AH, 09H
    INT 21H
    HLT
l:
    ; NEGATIVE
    MOV DX, OFFSET MSG3
    MOV AH, 09H
    INT 21H
END START
