#include "ft_printf.h"

static int  ft_printhex(unsigned long int num, char *hex)
{
    int count;

    count = 0;
    while (num)
    {
        if ((num / 16) < 10)
            write(1, &hex[num % 16], 1);
        else
            write(1, &hex[num / 16], 1);
        count++;
        num /= 16;
    }
    return (count);
}

void    ft_printhexsmall(int *count, unsigned long int num)
{    
    char    hex[] = "0123456789abcdef";

    *count += ft_printhex(num, hex);
}

void    ft_printhexbig(int *count, unsigned long int num)
{
    char    hex[] = "0123456789ABCDEF";

    *count += ft_printhex(num, hex);
}

void    ft_printptr(int *count, unsigned long int num)
{
    if (num == 0)
    {
        write(1, "(nil)", 5);
        *count += 5;
        return ;
    }
    else
    {
        *count += 2;
        write(1, "0x", 2);
        *count += ft_printhex(num, "0123456789abcdef");
    }
}
