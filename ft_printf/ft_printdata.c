#include "ft_printf.h"

void    ft_printdata(t_data *data, va_list arg_list, char specifier)
{
    char    print;

    if (specifier == 'c')
        ft_printchar(data, va_arg(arg_list, char));
    if (specifier == 's')
        ft_printstring(data, va_arg(arg_list, char *));
    if (specifier == 'p')
        ft_printptr(data, va_arg(arg_list, void *));
    if (specifier == 'd')
        ft_printint(data, va_arg(arg_list, int));
    if (specifier == 'i')
        ft_printint(data, va_arg(arg_list, int));
    if (specifier == 'u')
        ft_printuint(data, va_arg(arg_list, unsigned int));
    if (specifier == 'x')
        ft_printhexsmall(data, va_arg(arg_list, unsigned int));
    if (specifier == 'X')
        ft_printhexbig(data, va_arg(arg_list, unsigned int));
    if (specifier == '%')
        ft_printchar(data, '%');
}
