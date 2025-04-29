section .text
global ft_strcmp
extern __errno_location

ft_strcmp:
	test rdi, rdi
	jz .set_errno
	test rsi, rsi
	jz .set_errno

	xor rax, rax
	xor rcx, rcx

.loop:
	mov al, byte[rdi]
	mov cl, byte[rsi]
	cmp al, cl
	jne .diff
	test al, al
	jz .equal
	inc rsi
	inc rdi
	jmp .loop

.diff:
	movzx rax, al
	movzx rcx, cl
	sub rax, rcx
	ret
.equal:
	xor rax, rax
	ret

.set_errno:
	call [rel __errno_location wrt ..gotpc]
	mov dword[rax], 22
	mov rax, -1
	ret
