#include "libft/libft.h"
#include "ft_printf.h"

int    ft_parse(t_data *data, const char *input, va_list arg_list)
{
    int i;

    i = 0;
    while (input[i])
    {
        if (ft_strchr(data->specifiers, input[i]))
            break ;
        if (input[i] == '*')
            data->width = va_arg(arg_list, int);
        if (input[i] <= '9' && input[i] >= '0' && data->width == 0)
            data->width = ft_atoi(&input[i]);
        if (input[i] == '.' && data->precision == 0)
            data->precision = ft_atoi(&input[i + 1]);
        if (input[i] == '#')
            data->flag_alt = 1;
        if (input[i] == ' ')
            data->flag_space = 1;
        if (input[i] == '+')
            data->flag_plus = 1;
        if (input[i] == '-')
            data->flag_minus = 1;
        i++;
    }
    return (--i);
}
