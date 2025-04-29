#include <stdio.h>
#include <stdlib.h>

extern size_t ft_strlen(const char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern size_t ft_strcmp(char *s1, char *s2);

int main(void){
	
	printf("ft_strlen tests:\n");
	printf("	length of \"hello world !\": %ld\n", ft_strlen("hello world !"));
	printf("	length of \"test123\": %ld\n", ft_strlen("test123"));

	printf("\nft_strcpy tests:\n");
	char *dest = (char *)malloc(sizeof(char) * 5);
	if (!dest) {
		printf("Malloc failed\n");
		return 0;
	}

	printf("	dest = %s\n\n", ft_strcpy(dest, "test"));
	free(dest);

	printf("ft_strcmp tests:\n");
	
	printf("	diff between hello and hella: %ld\n", ft_strcmp("hello", "hella"));
	printf("	diff between h and h: %ld\n", ft_strcmp("h", "h"));
	printf("	diff between hella and hello: %ld\n", ft_strcmp("hella", "hello"));
	return 0;
}
