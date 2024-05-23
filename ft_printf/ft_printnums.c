#include "libft/libft.h"
#include "ft_printf.h"

void    ft_suffix(t_data *data, int len)
{
    data->count += len;
    if (data->flag_minus)
        data->flag_0 = 0;
    if (data->precision &&
            data->precision >= data->width)
        while (data->precision > len)
        {
            write(1, "0", 1);
            data->precision--;
        }
    if (data->width > data->precision)
        while (data->width > len)
        {
            if (data->flag_0)
                write(1, "0", 1);
            else
                write(1, " ", 1);
            data->width--;
        }
    if (data->flag_plus)
        data->flag_space = 0;
}

void    ft_count(t_data *data, int hex_bool, int len)
{
    if (data->flag_alt && hex_bool)
        data->count += 2;
    if (data->width && data->width > data->precision)
        data->count += (data->width - len);
    if (data->precision && data->precision >= data->width)
        data->count += (data->precision - len);
    if (data->flag_space || data->flag_plus)
        data->count += 1;
    data->count += len;
}

void    ft_printint(t_data *data, int num)
{
    char    *n;
    int     len;

    n = ft_itoa(num);
    len = ft_strlen(n);
    ft_suffix(data, len);
    ft_count(data, 0, len);
    if (data->flag_plus && num > 0)
        write(1, "+", 1);
    if (data->flag_space)
        write(1, " ", 1);
    write(1, n, len);
    free(n);
}

void    ft_printuint(t_data *data, unsigned int num)
{
    char    *n;
    int     len;

    n = ft_itoa(num);
    len = ft_strlen(n);
    ft_suffix(data, len);
    ft_count(data, 1, len);
    free(n);
}

void    ft_printhexsmall(t_data *data, unsigned int num)
{
    char    hex[] = "0123456789abcdef";
}

void    ft_printhexbig(t_data *data, unsigned int num)
{
    char    hex[] = "0123456789ABCDEF";
}
