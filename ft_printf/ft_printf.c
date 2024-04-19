#include "libftprintf.h"

static int	data(char *buff, char c, va_list args)
{
	int	count;

	count = 1;
	if (c == 'i')
		count = ft_strmove(buff, ft_itoa(va_arg(args, int)));
	else if (c == 'd')
		count = ft_strmove(buff, ft_itoa(va_arg(args, int)));
	else if (c == 'u')
		count = ft_strmove(buff, ft_uitoa(va_arg(args, int)));
	else if (c == 'c')
		*buff = va_arg(args, int);
	else if (c == 's')
		count = ft_strcpy(buff, va_arg(args, char *));
	else if (c == 'x')
		count = ft_strmove(buff, ft_itox(va_arg(args, int)));
	else if (c == 'X')
		count = ft_strmove(buff, ft_itoX(va_arg(args, int)));
	else if (c == 'p')
		count = ft_strmove(buff, ft_itoptr(va_arg(args, size_t)));
	else
		count = 0;
	return (count);
}

int	ft_printf(const char *input, ...)
{
	int	count;
	va_list	arg_list;
	char	buff[256];

	va_start(arg_list, input);
	count = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if(*input != '%')
				count += data(&buff[count], *(char *)input, arg_list);
			else
				buff[count++] = *input;
		}
		else
			buff[count++] = *(char *)input;
		input++;
	}
	write(1, buff, count);
	va_end(arg_list);
	return (count);
}

// Problem rn:
// Buffer max size is 256
// i COULD make it write as it goes and not need a buffer
// buttttt nahhh
// of course that way it could write infinitely but it would take quite a bit longer
// the changes are super basic too
