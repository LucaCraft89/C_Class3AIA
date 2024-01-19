.model small

.stack 
    100h
    
.data
    a db 10
    b db 7
    
.code
inizio:

    mov ax, @data
    mov ds, ax
    
; simulazione di
;             if (a>B) { 
;                cout << a; 
;             } else { 
;                cout << b; 
;             }

    cmp a,b
    je vero
    mov dh,b
    MOV AH,4Ch
    int 21h
    jmp fine
vero:
    mov dh,a
    MOV AH,4Ch
    int 21h
fine:
  
    
    
    