section .text
global ft_strcpy

ft_strcpy:
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

