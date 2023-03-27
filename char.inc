BITS 64

section .data
    CharBuffer db 0
    
section .text
PrintChar:
    push rbp
    mov rbp, rsp

    push rax
    push rbx
    push rcx 
    push rdx
    push rbp
    
    mov rax, 4
    mov rbx, 1

    mov rcx, [rbp + 16]
    mov [CharBuffer], rcx

    mov rcx, CharBuffer
    mov rdx, 1
    int 0x80

    pop rbp
    pop rdx 
    pop rcx
    pop rbx
    pop rax

    add rsi, 1

    pop rbp
    ret