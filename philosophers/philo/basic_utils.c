#include "philosophers.h"

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' \
		|| c == '\v' || c == '\f' \
		|| c == ' ');
}

long	ft_atoi(const char *str)
{
	long	total;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	total = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		i++;
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = (total * 10) + (sign *(str[i++] - '0'));
	}
	return (total);
}

size_t	ft_strlen(char *s)
{
	char	*t;

	t = s;
	while (*t)
		t++;
	return (t - s);
}

static void	__itoa_recursion(size_t nb, char *s)
{
	char	num;

	if (nb > 9)
	{
		__itoa_recursion(nb / 10, s);
		__itoa_recursion(nb % 10, s);
	}
	else
	{
		num = nb + '0';
		while (*s)
			s++;
		*s = num;
	}
}

char	*ft_itoa(size_t num)
{
	size_t	cpy;
	char	*str;
	int		size;

	cpy = num;
	size = 0;
	while (cpy / 10)
	{
		cpy /= 10;
		size++;
	}
	str = malloc(size + 1);
	memset(str, 0, size);
	__itoa_recursion(num, str);
	return (str);
}
