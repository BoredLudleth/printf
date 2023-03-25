BITS 64

PrintChar:
    push rbp
    mov rbp, rsp


    push rax
    push rbx
    push rcx 
    push rdx

    mov rdx, [rbp + 16]
    
    mov rax, 4
    mov rbx, 1
    mov rcx, rdx
    mov rdx, 1
    int 0x80

    pop rdx 
    pop rcx
    pop rbx
    pop rax

    add rsi, 1

    pop rbp
    ret