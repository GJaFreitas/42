#include "../ft_printf.h"

// Redirects to the appropriate printing fucntion

int	ft_nexus(char input, va_list args)
{
	int	count;

	count = 0;
	if (input == 'c')
		count = ft_printchar(va_arg(args, int));
	else if (input == 's')
		count = ft_printstring(va_arg(args, char *));
	else if (input == 'p')
		count = ft_printptr(va_arg(args, void *));
	else if (input == 'd')
		count = ft_printint(va_arg(args, int));
	else if (input == 'i')
		count = ft_printint(va_arg(args, int));
	else if (input == 'u')
		count = ft_printuint(va_arg(args, unsigned int));
	else if (input == 'x')
		count = ft_printhexsmall(va_arg(args, unsigned int));
	else if (input == 'X')
		count = ft_printhexbig(va_arg(args, unsigned int));
	else if (input == '%')
		count = ft_printchar('%');
	return (count);
}
