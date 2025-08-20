BITS 64

section .data
	; 222334565193649
	;upper_limit dq 1000000
    prime dq 0
	sol dq 0
	square dq 0
	index dq 5
section .bss
	arr: resb 100
section .text
    global _start
	upper_limit dq 100000000

_start:
	; TIL 4 HARDCODE
	xor rax,rax
	mov [sol],rax
	;call print_out
	xor rax,rax
	mov [sol],rax
	;call print_out
	mov rax, 1
	mov [sol],rax
	;call print_out
	mov rax, 1
	mov [sol],rax
	;call print_out
	xor rax,rax
	mov [sol],rax
	;call print_out

	xor rcx, [index] ; where to start in loop
    mov rbx, 2 ; first divisor, 2 < rbx < prime
	call primes_loop;

	mov rax, 60
    xor rdi, rdi
    syscall;exit
;---------------------------------loop-----------------------------
primes_loop:
	mov rcx,[index]
	cmp rcx,[upper_limit] ;current index comapred to until_value
	je finish_loop

	mov [prime], rcx
	mov rbx, 2 ; ready to calc now
	
	push rcx
	call calc_prime
	pop rcx

	inc rcx
	mov [index], rcx
	jmp primes_loop
	

finish_loop:
	mov rax, 60
    xor rdi, rdi
    syscall
;---------------------------------loop-end-----------------------------
;---------------------------------check-prime-----------------------------
print_out:
	mov rax, 1
    mov rdi, 1
    mov rsi, sol
    mov rdx, 8
    syscall
	ret
is_not_prime:
	xor rax,rax
	mov [sol],rax
	
	;call print_out
	ret

is_prime:
	mov rax,1
	mov [sol],rax

	;call print_out
	ret

square_rbx:
	mov rax,rbx
	mul rbx
	mov [square],rax
	ret

calc_prime:
	;rbx*brx -> [square] 
	call square_rbx
	
	;get prime
	mov rax, [prime]
	cmp rax, [square] ; cmp root(num) with i (basically)
	jl is_prime

	;calc new mod
	xor rdx,rdx
	div rbx ; rdx should hold the remain, rdx = rax % rbx

	; num %n ==0??
	cmp rdx,0
	je is_not_prime
	;inc divisor, goto next iteration
	inc rbx ; i++
	jmp calc_prime;
; div b -> a/b in a. a%b in d
;---------------------------------check-prime-end-----------------------------