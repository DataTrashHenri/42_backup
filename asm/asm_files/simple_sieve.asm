BITS 64


section .bss
	arr: resb 1000000

section .data
	limit dq 1000000
	output db 0
	sqrt dq 0

section .text
	global _start

_start:
	mov rax, 2
	mov r9, 1
	call mem_set
 
	call find_sqrt

	mov rcx, 1
	xor rsi,rsi
	xor r9,r9 ; later arr set to 0 if not prime
	mov rdx, [sqrt]
	mov r8, [limit]
	call search_array

	xor rax, rax 	
	xor r9, r9 	 ;------- ENABLE TO WRITE TO BIN-FILE
	call read_all	

	mov rax, 60
    xor rdi, rdi
    syscall
;---------------------------------START_DEF-----------------------------------

;--------------------------------MARK_MULITPLES------------------------------

mark_multibles:
	; r8 upper limit, e.g 100 000 000
	
	add rsi, rcx
	cmp rsi, r8
	jg exit
	
	; write in arr
	mov byte  [rel arr + rsi], r9b ; writes 0

	jmp mark_multibles

search_array:
	; rxc starts 2, then base of every yet prime
	; rdx limit

	inc rcx

	cmp rcx, rdx
	jg exit
	
	mov al, [arr + rcx]

	cmp al, 1
	jne search_array

	mov rsi,rcx ; set starting point !
	call mark_multibles

	jmp search_array

;--------------------------------MARK_MULITPLES------------------------------

;---------------------------------read_arr_to_out-----------------------------
read_all:
	;req rax,rbx = 0
	;def limit upper bound, arr array, output 0/1?
	cmp rax, [limit]
	je exit

	mov r9b, [arr + rax]
	mov [output], r9b
	
	push rax
	mov rax, 1
    mov rdi, 1
    mov rsi, output
    mov rdx, 1
    syscall
	pop rax
	
	
	inc rax
	jmp read_all
;---------------------------------write_end-----------------------------

;---------------------------------memset-----------------------------
mem_set:
	
	mov rdi, arr
	mov rcx, [limit]
	mov al,1
	rep stosb ; repeat store string byte, al, what to write, rcx, how often, rdi, where
	ret
;---------------------------------memset-ende-----------------------------

;---------------------------------find_sqrt-----------------------------
find_sqrt:
	;stored in [sqrt]
	xor r9,r9
	mov rsi, [limit]
	jmp loop

loop:
	;rbx -> counter
	mov rax,r9
	mul r9
	cmp rax,rsi
	je loop_end
	inc r9
	jmp loop

loop_end:
	mov [sqrt], r9
	ret

;---------------------------------find_sqrt-ende-----------------------------

;---------------------------------general-labels-----------------------------
exit:
	ret

