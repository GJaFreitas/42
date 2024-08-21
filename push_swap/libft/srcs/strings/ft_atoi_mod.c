#include "../../libft.h"

static int	ft_isspace(char c)
{
	return (c == '\n' 
		|| c == '\t' 
		|| c == '\v' 
		|| c == '\r' 
		|| c == '\f' 
		|| c == ' ');
}

int	ft_atoi_mod(const char *str, char **index)
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
	while (ft_isdigit(str[i]))
	{
		total = (total * 10) + (sign *(str[i++] - '0'));
        *index = *index + 1;
	}
	return (total);
}
