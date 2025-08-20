BITS 64

section .data
    num dq 0

section .text
    global _start

_start:
	xor rax, rax	
    mov rbx, 100 ; loop upper limit
	call loop_test
	
	mov rax, 60
    xor rdi, rdi
    syscall

write_file:
	mov rax, 1
    mov rdi, 1
    mov rsi, num
    mov rdx, 8
    syscall
	ret

loop_test: ; rax,rbx cmp
	mov [num], rax
	
	push rax
	call write_file
	pop rax
	
	inc rax
	cmp rax,rbx
	jle loop_test
	ret
