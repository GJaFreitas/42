#include "libft/libft.h"
#include <stdarg.h>

// Should i use enums? Can i use them?

int	data(char *buff, char c, va_list args)
{
	int	count;

	count = 1;
	if (c == 'i')
		count = ft_strcat(buff, ft_itoa(va_arg(args, int)));
	else if (c == 'c')
		*buff = va_arg(args, int);
	else if (c == 's')
		count = ft_strcat(buff, va_arg(args, char *));
	else if (c == 'd')
		count = ft_strcat(buff, ft_itoa(va_arg(args, int)));
	return (count);
}

int	ft_printf(const char *input, ...)
{
	int	count;
	int	arg_count;
	va_list	arg_list;
	char	buff[256];

	va_start(arg_list, input);
	count = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if(*(input) != '%')
				count += data(&buff[count], *(char *)input, arg_list);
			else
				buff[count] = *input;
		}
		else
			buff[count++] = *(char *)input;
		input++;
	}
	write(1, buff, count);
	va_end(arg_list);
}

int main()
{
}
