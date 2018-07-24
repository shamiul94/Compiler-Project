.model small
.stack 100h

.data
t0    dw    ?
t1   dw   4    dup(?)  
t2    dw    ?
t3    dw    ?
t4    dw    ?
t5    dw    ?
t6    dw    ?
t7    dw    ?
t8    dw    ?
.code
main PROC NEAR
mov ax , t0
inc ax
mov t0 , ax
mov ax , 3 
mov  t0 , ax
mov bx , 2
add bx , bx 
mov ax , t1[bx] 
mov t2 , ax
mov ax , t2[bx]
inc ax
mov t2[bx] , ax
mov t3 ,  t2[bx]
mov bx , 1
add bx , bx 
mov ax , t3[bx] 
mov t4 , ax
mov ax , t4[bx]
mov t5 , ax
mov ax , t5
cmp ax , t0
jle L0
mov t6 , 0
jmp L1
L0 :  
mov t6 , 1
L1 : 
mov ax , t6 
cmp ax , 0
je L2
mov bx , 2
add bx , bx 
mov ax , t5[bx] 
mov t7 , ax
mov ax , t7[bx]
mov t8 , ax
mov ax , t8 
mov  t0 , ax
L2 : 
mov ah , 4ch
int 21h
main  ENDP

