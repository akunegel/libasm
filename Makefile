ASM_SRCS = srcs/ft_strcmp.s srcs/ft_strlen.s srcs/ft_strcpy.s
ASM_OBJS = $(ASM_SRCS:.s=.o)

all: libasm.a
%.o: %.s
	nasm -f elf64 -o $@ $<

libasm.a: $(ASM_OBJS)
	ar rcs libasm.a $(ASM_OBJS)

clean:
	rm -f srcs/*.o

fclean:
	rm -f srcs/*.o libasm.a tests

test:
	gcc -g -o tests test.c -L. -lasm 

re: fclean all