#include "ft_printf.h"

void    ft_printint(int *count, int num)
{
    char    *n_string;
    int     len;

    n_string = ft_itoa(num);
    len = ft_strlen(n_string);
    *count += len;
    write(1, n_string, len);
}

void    ft_printuint(int *count, unsigned long int num)
{
    char    *n_string;
    int     len;

    n_string = ft_itoa(num);
    len = ft_strlen(n_string);
    *count += len;
    write(1, n_string, len);
}
