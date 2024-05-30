#include "ft_printf.h"

static void ft_rev(char *str, int len)
{
    int i;
    int j;
    char    temp;

    i = 0;
    j = len;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

static int  ft_printhex(unsigned long int num, char *hex)
{
    int     count;
    char    number[12];

    count = 0;
    while (num)
    {
        number[count] = hex[num % 16];
        count++;
        num /= 16;
    }
    ft_rev(number, count - 1);
    write(1, number, count);
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
