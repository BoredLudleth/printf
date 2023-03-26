BITS 64

section .data
    Bin db 'b', 0
    One db '1', 0
    Zero db '0', 0

section .text
BinaryPrint:
    push rbp
    mov rbp, rsp

    push rax
    push rcx
    mov rcx, 64

    mov rax, [rbp + 16]
    mov rax, [rax]

SkipZeros:
    shl rax, 1
    jc PrintOne
    loop SkipZeros
    
    push rax
    push rbx
    push rcx 
    push rdx

    mov rax, 4
    mov rbx, 1
    mov rcx, Zero
    mov rdx, 1
    int 0x80

    pop rdx 
    pop rcx
    pop rbx
    pop rax
    jmp EndLetter

PrintB:
    shl rax, 1
    jc PrintOne
    jnc PrintZero
BackToB:
    loop PrintB
    jmp EndLetter

PrintOne:

    push rax
    push rbx
    push rcx 
    push rdx

    mov rax, 4
    mov rbx, 1
    mov rcx, One
    mov rdx, 1
    int 0x80

    pop rdx 
    pop rcx
    pop rbx
    pop rax
    jmp BackToB

PrintZero:
    push rax
    push rbx
    push rcx 
    push rdx

    mov rax, 4
    mov rbx, 1
    mov rcx, Zero
    mov rdx, 1
    int 0x80

    pop rdx 
    pop rcx
    pop rbx
    pop rax
    jmp BackToB

EndLetter:
    push rax
    push rbx
    push rcx 
    push rdx

    mov rax, 4
    mov rbx, 1
    mov rcx, Bin
    mov rdx, 1
    int 0x80

    pop rdx 
    pop rcx
    pop rbx
    pop rax

    pop rcx
    pop rax
    pop rbp
    ret