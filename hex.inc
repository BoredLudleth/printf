BITS 64

section .data
    HexBuffer dq 0

section .text

HexPrint:
    push rbp
    mov rbp, rsp

    push rax
    push rbx
    push rcx
    push rdx
    xor rcx, rcx

    mov eax, [rbp + 16]
    mov eax, [eax]

PrintHex:
    mov edx, 0
    mov ebx, 16
    div ebx
    cmp edx, 9
    ja Alpha
    jmp Number

Alpha:
    add edx, 'A' - 10
    push rdx
    jmp IsCompleteHex

Number:
    add edx, '0'
    push rdx

IsCompleteHex:
    add rcx, 1
    cmp eax, 0
    je PrintingLoopHex
    jmp PrintHex

PrintingLoopHex:
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

EndHex:
    pop rdx
    pop rax
    pop rbp
    ret