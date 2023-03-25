BITS 64

printSym:
    push rbp
    mov rbp, rsp
    mov rsi, [rbp + 16]

    push rax
    push rbx
    push rcx 
    push rdx

    mov rax, 4
    mov rbx, 1
    mov rcx, rsi
    mov rdx, 1
    int 0x80

    pop rdx 
    pop rcx
    pop rbx
    pop rax

    add rsi, 1

    pop rbp
    ret