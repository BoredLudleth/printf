BITS 64                                                     ; chosen 64-bits registers model

global _start

section .data
    msg db  "%c - char", 0xA, "%s - string", 0xA, "%x - hex", 0xA, "%o - oct", 0xA, "%b - bin", 0xA, "Hello darkness my old friend%%", 0xA, 0           ; phrase to print
    var1 db 'v'
    var2 db "1488", 0
    var3 dq 58
    var4 dq 58
    var5 dq 58

section .text
    %include "printf.inc"                                   ; add body of printf
    %include "printsym.inc"
    %include "printspecial.inc"
    %include "binary.inc"
    %include "char.inc"
    %include "oct.inc"
    %include "hex.inc"
    %include "string.inc"

    _start:

        mov rbx, var5
        push rbx

        mov rbx, var4
        push rbx

        mov rbx, var3
        push rbx

        mov rbx, var2
        push rbx

        mov rbx, var1
        push rbx

        mov rax, msg
        push rax                                            ; pushing arguments in stack

        call printf

        mov rax, 60                                         ; exit
        mov rdi, 0
        syscall