section .text
global ft_strcmp

ft_strcmp:
	xor rax, rax
	xor rcx, rcx
	jmp .compare
.loop:
	inc rdi
	inc rsi

.compare:
	mov al, byte[rdi]
	mov cl, byte[rsi]
	test al, al
	jz .check_s2_ended
	cmp al, cl
	jne .diff
	test cl, cl
	jnz .loop

.diff:
	sub rax, rcx
	ret 

.equal:
	xor rax, rax
	ret

.check_s2_ended:
	test cl, cl
	jz .equal
