#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

// Should i use enums? Can i use them?

int	data(char *buff, char type, va_list args, int arg_count)
{
	if (type == 'i')
		ft_itoa(args, int);
}

int	ft_printf(const char *input, ...)
{
	int	count;
	int	arg_count;
	va_list	arg_list;
	char	*buff[256];

	va_start(arg_list, input);
	count = 0;
	while (*input)
	{
		if (*input == '%')
		{
			if(*(input + 1) != '%')
				count += data(buff + count, *input, arg_list, arg_count);
			else
				buff[count] = *input;
			input++;
		}
		else
		{
			buff[count] = *(char *)input;
			count++;
		}
		input++;
	}
	write(1, buff, count);
	va_end(arg_list);
}

int main()
{
}
