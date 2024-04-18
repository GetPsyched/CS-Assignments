; WAP to subtract 2 8-bit multi-digit numbers

.data
a db "Enter the first 2 digit number: $"
b db "Enter the second 2 digit number: $"
c db "Difference is: $"
n db 10

.code
lea dx, a
mov ah,09h
int 21h
mov ah,01h
int 21h
sub al,30h
mov bh,al
mov ah,01h
int 21h
sub al,30h
mov bl,al

; 2nd number
mov ah,02h
mov dl,10
int 21h
mov dl,13
int 21h
lea dx,b
mov ah,09h
int 21h
mov ah,01h
int 21h
sub al,30h
mov ch,al
mov ah,01h
int 21h
sub al,30h
mov cl,al
mov ah,02h
mov dl,10
int 21h
mov dl,13
int 21h
lea dx,c
mov ah,09h
int 21h
cmp bh,ch
JL exchange
JMP subtract
exchange:
    mov ah,02h
    mov dl,'-'
    int 21h
    xchg bx,cx
subtract:
    mov ax,bx
    sub al,cl
    aas
    sub ah,ch
    aas
    add ax,3030h
    mov dx,ax
    mov ah,02h
    xchg dh,dl
    int 21h
    xchg dh,dl
    int 21h
    hlt
