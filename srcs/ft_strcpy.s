section .text
global ft_strcpy
extern __errno_location

ft_strcpy:
	test rdi, rdi
	jz .set_errno
	test rsi, rsi
	jz .set_errno

	mov rax, rdi
	test rsi, rsi
	jz .done
.loop:
	mov cl, byte[rsi]
	mov byte[rdi], cl
	inc rdi
	inc rsi
	test cl, cl
	jnz .loop
.done:
	ret

.set_errno:
	call [rel __errno_location wrt ..gotpc]
	mov dword[rax], 22
	mov rax, -1
	ret
