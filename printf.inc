BITS 64

    %include "printsym.inc"
    %include "printspecial.inc"
    %include "binary.inc"
    %include "char.inc"
    %include "oct.inc"
    %include "hex.inc"
    %include "string.inc"
    %include "int.inc"

printf:
    push rbp
    mov rbp, rsp

    mov rdi, 1                          ; why?
    mov r8, 24                          ; r8 - delta in stack to take arguments
    mov rsi, [rbp + r8]                 ; string such as "Hello darkness my old friend"                 

Printing:
    mov dl, byte [rsi]

    cmp dl, 0                           ; if 0, then the end of string
    je PrintfComplete  
     
    cmp dl, '%'
    je PrintSpecial
    jmp PrintSymbol

PrintSpecial:
    add rsi, 1                          ; take symbol after %
                                        ; should i check it on rightness? and give error code
    mov rdx, [rbp + r8 + 8]                 ; need check if it's end of stack

    push rdx                            ; print %smth
    push rsi 

    call printStrangeSym
    pop rsi
    pop rdx

    add rsi, 1

    jmp Printing

PrintSymbol:                            ; print symbol 
    push rsi
    call printSym
    pop rsi

    add rsi, 1

    jmp Printing

PrintfComplete:                         ;exit from function
    pop rbp
    ret