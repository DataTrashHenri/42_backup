BITS 64


section .bss
	arr: resq 250000

section .data
	limit dq 250000
	output dq 0
	index dq 0
	num dq 12345
	sqrt dq 0

section .text
	global _start

_start:
	mov rax, 64
	mov rbx, 1
	mov [num] , rbx
	call mem_set

	mov rbx, 250000
	mov [num], rbx
	call find_sqrt

	mov rax, 249980 ;  index
	mov rbx , [sqrt] 	; value
	mov [num], rbx
	call put_num

	xor rax, rax
	xor rbx, rbx
	call read_all

	mov rax, 60
    xor rdi, rdi
    syscall
;---------------------------------START_DEF-----------------------------------

;---------------------------------read_arr_to_out-----------------------------
read_all:
	;req rax,rbx = 0
	;def limit upper bound, arr array, output 0/1?
	cmp rax, [limit]
	je exit

	lea rdi, [arr]
	mov rbx, [rdi + rax*8]
	mov [output], rbx
	
	push rax
	mov rax, 1
    mov rdi, 1
    mov rsi, output
    mov rdx, 8
    syscall
	pop rax
	
	
	inc rax
	jmp read_all
;---------------------------------write_end-----------------------------

;---------------------------------memset-----------------------------
mem_set:
	;req rbx = 1, rax = 0
	;def limit upper bound, index
	cmp rax, [limit]
	je exit

	mov [num], rbx
	call put_num

	inc rax
	jmp mem_set
;---------------------------------memset-ende-----------------------------

;---------------------------------find_sqrt-----------------------------
find_sqrt:
	;stored in [sqrt]
	xor rbx,rbx
	jmp loop

loop:
	;rbx -> counter
	mov rax,rbx
	mul rbx
	cmp rax,[num]
	je loop_end
	inc rbx
	jmp loop

loop_end:
	mov [sqrt], rbx
	ret

;---------------------------------find_sqrt-ende-----------------------------

;---------------------------------general-labels-----------------------------
exit:
	ret

put_num:
	; req  [num], arr, rax = index
	;def , rax in arr, num what to be moved in arr
	;mov rax, [index]
	mov rbx, [num]
	lea rdi, [arr]
	mov [rdi + rax*8], rbx
	ret
