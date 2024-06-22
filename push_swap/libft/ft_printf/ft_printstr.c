#include "ft_printf.h"

void    ft_printchar(int *count, char c)
{
    *count += 1;
    write(1, &c, 1);
}

void    ft_printstring(int *count, char *str)
{
    int len;

    len = ft_strlen(str);
    *count += len;
    write(1, str, len);
}
