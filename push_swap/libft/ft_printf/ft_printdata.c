#include "ft_printf.h"

int    ft_printdata(int *count, char specifier, va_list arg_list)
{
    if (specifier == 'c')
        ft_printchar(count, va_arg(arg_list, int));
    else if (specifier == 's')
        ft_printstring(count, va_arg(arg_list, char *));
    else if (specifier == 'p')
        ft_printptr(count, (unsigned long int)va_arg(arg_list, void *));
    else if (specifier == 'd')
        ft_printint(count, va_arg(arg_list, int));
    else if (specifier == 'i')
        ft_printint(count, va_arg(arg_list, int));
    else if (specifier == 'u')
        ft_printuint(count, va_arg(arg_list, unsigned int));
    else if (specifier == 'x')
        ft_printhexsmall(count, va_arg(arg_list, unsigned int));
    else if (specifier == 'X')
        ft_printhexbig(count, va_arg(arg_list, unsigned int));
    else if (specifier == '%')
        ft_printchar(count, '%');
    else
        return (0);
    return (1);
}
