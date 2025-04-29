#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

extern size_t ft_strlen(const char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(char *s1, char *s2);

int main(void) {
    printf("ft_strlen tests:\n");
	
	errno = 0;
	size_t res2 = ft_strlen("hello world !");
    printf("    length of \"hello world !\": %ld\n | errno = %d\n", res2, errno);
    
	errno = 0;
	res2 = ft_strlen("test123");
	printf("    length of \"test123\": %ld\n | errno = %d\n", res2, errno);

	errno = 0;
	res2 = ft_strlen(NULL);
	printf("	length of NULL string: %ld\n | errno = %d\n", res2, errno);


    printf("\n\nft_strcpy tests:\n");
    char *dest = (char *)malloc(sizeof(char) * 5);
    if (!dest) {
        printf("Malloc failed\n");
        return 0;
    }
	errno = 0;
	char *str = ft_strcpy(dest, "test");
    printf("    dest = %s\n | errno = %d\n", str, errno);
	free(dest);

	char dest2[20];
	errno = 0;
	str = ft_strcpy(dest, NULL);
    printf("errno of null source = %d\n", errno);
	
	errno = 0;
	str = ft_strcpy(NULL, "test");
    printf("errno of null dest = %d\n", errno);

    printf("\n\nft_strcmp tests:\n");

	errno = 0;
	int res = ft_strcmp("hello", "hella");
    printf("    diff between hello and hella: %d\n | errno = %d\n", res, errno);
	
	errno = 0;
	res = ft_strcmp("h", "h");
    printf("    diff between h and h: %d\n | errno = %d\n", res, errno);
    
	errno = 0;
	res = ft_strcmp("hel", "hello");
    printf("    diff between hel and hello: %d\n | errno = %d\n", res, errno);
    
	errno = 0;
	res = ft_strcmp("hello", "hel");
    printf("    diff between hello and hel: %d\n | errno = %d\n", res, errno);
    
	errno = 0;
	res = ft_strcmp("hello", NULL);
    printf("    diff between hello and NULL: %d\n | errno = %d\n", res, errno);
    
	errno = 0;
	res = ft_strcmp(NULL, "hello");
    printf("    diff between NULL and hello: %d\n | errno = %d\n", res, errno);
    return 0;
}
