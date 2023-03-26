BITS 64

section .data
    OctBuffer dq 0

section .text

OctalPrint:
    push rbp
    mov rbp, rsp

    push rax
    push rbx
    push rcx
    push rdx
    xor rcx, rcx

    mov eax, [rbp + 16]
    mov eax, [eax]

PrintOct:
    mov edx, 0
    mov ebx, 8
    div ebx
    add edx, '0'

    push rdx

IsCompleteOct:
    add rcx, 1
    cmp rax, 0
    je EndOct
    jmp PrintOct

EndOct:
PrintLoop:
    pop rdx
    mov [OctBuffer], rdx

    push rcx

    mov rax, 4
    mov rbx, 1
    mov rcx, OctBuffer
    mov rdx, 1
    int 0x80

    pop rcx
    dec rcx
    
    cmp rcx, 0
    jne PrintLoop

    pop rdx
    pop rcx
    pop rbx
    pop rax
    pop rbp
    ret