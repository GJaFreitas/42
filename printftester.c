#include "ft_printf/ft_printf.h"
#include <stdio.h>

// TODO:
// hex is printing in the wrong order??????????
int main(int argc, char **argv)
{
	(void)argc;
	void	*ptr;
	int	i = 42;
	ptr = NULL;
	ft_printf("Testing Testing printf\n");
	ft_printf("Void *:\n");
	ft_printf("%p\n", ptr);
	printf("Normal printf: %p\n", ptr);
	ft_printf("Printing a %% without a specifier after:%\n");
	printf("Normal printf: %\n");
	ft_printf("Int, hex, char, unsigned max\n");
	ft_printf("Int: %d\n", 42);
	ft_printf("Hex: %X\n", 42);
	ft_printf("Char: %c\n", 42);
	ft_printf("Unsigned: %u\n", 4294967295);
	printf("Normal printf:\n");
	printf("Int: %d\n", 42);
	printf("Hex: %X\n", 42);
	printf("Char: %c\n", 42);
	printf("Unsigned: %u\n", 4294967295);
    /*
	ft_printf("Stringssss\n");
	ft_printf("%s", "this whole thing is a string\n");
	printf("Normal printf: %s", "this whole thing is a string\n");
	*/

	/*
	ft_printf("And now for the 'what the fuck are you doing?' tests\n");
	ft_printf("%%s but giving it a char:\n");
	printf("Normal printf: %s\n", 'c');
	ft_printf("%s\n", 'c');
	
	They both seg fault, nice.

	*/
}
