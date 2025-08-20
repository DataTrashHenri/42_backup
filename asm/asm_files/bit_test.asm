BITS 64

section .bss
	arr resq 3 ;24bytes, 192 bits 

section .data
	output dq 0

section .text
	global _start

%macro print_bits 1 ; qbyte, working

	mov [output], %1

	mov rax, 1
    mov rdi, 1
    mov rsi, output
    mov rdx, 8
    syscall

%endmacro

%macro set_in_array 1
    mov rax, %1
    xor rdx, rdx
    mov rcx, 64

	div rcx

    mov rsi, rax; element index
    mov r8, [rel arr + rsi*8]
    
	mov r9, 1
    mov rcx, rdx; 
    
	shl r9, cl; um den remanider nach links
    or r8, r9 
    mov [rel arr + rsi*8], r8
%endmacro
_start:

	;mov qword [rel arr],0

	mov rdi, arr
	mov rcx, 3
	mov rax, 0
	rep stosq

	mov r9, [arr];  to be shifted

	xor rcx,rcx
	xor rdx,rdx
	
	mov r9, 0
	set_in_array r9

	xor rax,rax

	call print_all_bits


	; mov r9, [arr]
	; print_bits r9, r8
	; mov r9, [arr + 8]
	; print_bits r9, r8
	; mov r9, [arr + 16]
	; print_bits r9, r8



	mov rax, 60
	xor rdi,rdi
	syscall

print_all_bits:
	cmp rax, 3
	jge exit

	push rax
	mov r9, [arr + 8*rax]
	print_bits r9
	pop rax

	inc rax
	jmp print_all_bits



read_bits:
	cmp rsi, 8
	je exit

	mov r8b, r9b
	
	and r8b, 1; get current bit
	shr r9b, 1; shr for next iter



	mov [output], r8b

	push rsi
	mov rax, 1
    mov rdi, 1
    mov rsi, output
    mov rdx, 1
    syscall
	pop rsi

	inc rsi
	jmp read_bits

	

exit:
	ret
