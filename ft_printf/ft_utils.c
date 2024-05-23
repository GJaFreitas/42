#include "ft_printf.h"
#include "libft/libft.h"

t_data    *ft_initialize()
{
    t_data *data;

    data = malloc(sizeof(t_data));
    data->precision = 0;
    data->width = 0;
    data->count = 0;
    data->flag_0 = 0;
    data->flag_alt = 0;
    data->flag_plus = 0;
    data->flag_minus = 0;
    data->flag_space = 0;
    data->flag_precision = 0;
}

