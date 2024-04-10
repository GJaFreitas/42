#include <stdio.h>
#include "../libft.h"

static char	strmapi_assist(unsigned int i, char c)
{
	return ('a');
}

int	main(void)
{
	char teststring[256];
	char *duplicate;
	char *substr;
	printf("Testing Testing\n");
	printf("Strcpy: %zu\n", ft_strlcpy(teststring, "Success :)", 256));
	printf("Strlen: %zu\n", ft_strlen("why hello there, 42 is so cool yupi. palha"));
	printf("Atoi: %d\n", ft_atoi("  -42"));
	printf("Strstr: %s\n", ft_strnstr("Ola bom trabalho", "bom", 8));
	duplicate = ft_strdup(teststring);
	printf("Strdup: %s\n", duplicate);
	if (!ft_strncmp("Success :)", "Success :)", 10))
		printf("Strcmp: Also correct\n");
	printf("Memset: %s | %s\n", duplicate, (char *)ft_memset(teststring, 42, 4));
	printf("Memcpy: %s | %s\n", teststring, (char *)ft_memcpy(duplicate, teststring, 10));
	if (!ft_memcmp(duplicate, teststring, 10))
		printf("Memcmp: Working as intended\n");
	substr = ft_substr(teststring, 4, 10);
	printf("itoa: %s\n", ft_itoa(-123));
	printf("strmapi: %s %s\n", duplicate, ft_strmapi(duplicate, strmapi_assist(0, 0)));
	return 0;
}
