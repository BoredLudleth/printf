BITS 64


section .data
    DecBuffer db 0

section .text

DecPrint:
    push rbp
    mov rbp, rsp

    push rax
    push rbx
    push rcx
    push rdx

    xor rax, rax
    xor rcx, rcx

    mov eax, [rbp + 16]                     ;signum eax
    cmp eax, 2147483648

    jae NegativeNum
    jmp PositiveNum

NegativeNum:
    push rax
    push rbx
    push rcx
    push rdx

    mov rax, 4
    mov rbx, 1
    mov dl, '-'
    mov [DecBuffer], dl
    mov rcx, DecBuffer
    mov rdx, 1
    int 0x80

    pop rdx
    pop rcx
    pop rbx
    pop rax

    neg eax

PositiveNum:
PrintDec:
    mov edx, 0
    mov ebx, 10
    div ebx
    add edx, '0'

    push rdx

IsCompleteDec:
    add rcx, 1
    cmp rax, 0
    je EndDec
    jmp PrintDec

EndDec:
PrintLoopDec:
    pop rdx
    mov [DecBuffer], rdx

    push rcx

    mov rax, 4
    mov rbx, 1
    mov rcx, DecBuffer
    mov rdx, 1
    int 0x80

    pop rcx
    dec rcx
    
    cmp rcx, 0
    jne PrintLoopDec

    pop rdx
    pop rcx
    pop rbx
    pop rax
    pop rbp
    ret