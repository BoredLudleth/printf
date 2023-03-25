BITS 64                                                     ; chosen 64-bits registers model

global _start

section .data
    msg db "%c - char %b - bin", 0xA, "Hello darkness my old friend%%", 0xA, 0           ; phrase to print
    var2 db 'U'
    var1 dq 58

section .text
    %include "printf.inc"                                   ; add body of printf
    %include "printsym.inc"
    %include "printspecial.inc"
    %include "binary.inc"
    %include "printchar.inc"

    _start:

        mov rbx, [var1]
        push rbx

        xor bx,  bx
        mov rbx, var2
        push rbx

        mov rax, msg
        push rax                                            ; pushing arguments in stack

        call printf

        mov rax, 60                                         ; exit
        mov rdi, 0
        syscall