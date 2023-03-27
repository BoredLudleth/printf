BITS 64                                                     ; chosen 64-bits registers model

global _printf

section .text
    %include "printf.inc"                                   ; add body of printf
    

    _printf:
        push r9         			
        push r8         
        push rcx        
        push rdx        
        push rsi	    
        push rdi
        push rbp

        call printf

        pop rbp
        pop rdi
        pop rsi
        pop rdx
        pop rcx
        pop r8
        pop r9

    ret