global main

section .text
main:
    mov rax, 1       ; System call number for write
    mov rdi, 1       ; File descriptor for standard output (stdout)
    mov rsi, message ; Pointer to the message string
    mov rdx, 13      ; Length of the message string, including the newline character
    syscall

    mov rax, 60      ; System call number for exit
    xor rdi, rdi     ; Exit code 0
    syscall

section .data
message: db "Hello, World", 10 ; The message string with a newline character

