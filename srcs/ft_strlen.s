section .text
global ft_strlen
extern __errno_location

ft_strlen:
	test rdi, rdi
	jz .set_errno
	xor rax, rax

.loop:
	cmp byte[rdi], 0
	je .done
	inc rax
	inc rdi
	jmp .loop
.done:
	ret

.set_errno:
	call [rel __errno_location wrt ..gotpc]
	mov dword[rax], 22
	mov rax, -1
	ret