BITS 64

StringPrint:
    push rbp
    mov rbp, rsp

    push rax
    push rbx
    push rcx 
    push rdx

    mov rax, 4
    mov rbx, 1
    mov rcx, [rbp + 16]
    push rcx
    call LenStr
    pop rcx
    int 0x80

    pop rdx 
    pop rcx
    pop rbx
    pop rax

    add rsi, 1

    pop rbp
    ret

LenStr:
    push rbp 
    mov rbp, rsp 

    push rax
    push rcx
    push rdi
    
    mov rdi, [rbp + 16]
    mov al, 0
    mov rcx, 0
    not rcx

    repne scasb
    mov rax, [rbp + 16]
    sub rdi, rax
    mov rdx, rdi

    pop rdi 
    pop rcx
    pop rax

    pop rbp
    ret