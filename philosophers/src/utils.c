#include "../philosophers.h"

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' \
		|| c == '\v' || c == '\f' \
		|| c == ' ');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	total;

	sign = 1;
	i = 0;
	total = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = (total * 10) + (sign *(str[i++] - '0'));
	}
	return (total);
}

