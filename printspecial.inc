BITS 64

printStrangeSym:
    push rbp
    mov rbp, rsp

    mov rsi, [rbp + 16]                     ; argument take, after that i need jump-table
    xor rbx, rbx
    mov bl, [rsi]

    cmp rbx, '$'                            ; out of print range
    jna .Error

    cmp rbx, 'x'                            ; out of print range
    ja .Error

    mov     rax, [.JumpTable + (rbx - '%')*8]       ; jumping..
    jmp     rax

.PercentPrint:
    push rsi
    call printSym
    pop rsi

    jmp .SnitchExit

.BinaryPrint:
    add r8, 8
    mov rcx, [rbp + 24]
    push rcx

    call BinaryPrint

    pop rcx
    jmp .SnitchExit

.CharPrint:
    add r8, 8
    mov rcx, [rbp + 24]
    push rcx

    call PrintChar

    pop rcx
    jmp .SnitchExit

.DecPrint:
    mov bx, 0
    jmp .SnitchExit

.OctalPrint:
    add r8, 8
    mov rcx, [rbp + 24]
    push rcx

    call OctalPrint

    pop rcx
    jmp .SnitchExit

.PrintString:
    add r8, 8
    mov rcx, [rbp + 24]
    push rcx

    call StringPrint

    pop rcx
    jmp .SnitchExit

.HexPrint:
    add r8, 8
    mov rcx, [rbp + 24]
    push rcx

    call HexPrint

    pop rcx
    jmp .SnitchExit

.Error:
    mov cx, 33  
    jmp .SnitchExit

.SnitchExit:
    pop rbp
    ret

section .rodata
.JumpTable:
    dq  .PercentPrint       ; %% [0]
    times 60 dq  .Error     ; %& - %a [1] - [60]
    dq  .BinaryPrint        ; %b [61]
    dq  .CharPrint          ; %c [62]
    dq  .DecPrint           ; %d [63]
    times 10 dq  .Error     ; %e - %n [64] - [73]
    dq .OctalPrint          ; %o [74]
    times 3 dq  .Error      ; %p - %r [75] - [77]
    dq  .PrintString        ; %s [78]
    times 4 dq  .Error      ; %t - %w [79] - [82]
    dq  .HexPrint           ; %x [83]

section .text