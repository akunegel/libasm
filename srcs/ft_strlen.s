external __errno_location

section .text
global ft_strlen

ft_strlen:
	mov rax, 0

.loop:
	cmp byte[rdi], 0
	je .done
	inc rax
	inc rdi
	jmp .loop
.done:
	ret
