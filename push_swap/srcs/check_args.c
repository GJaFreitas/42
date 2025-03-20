#include "../includes/push_swap.h"

static int	__just_nums(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_args(int argc, char **argv)
{
	int	tmp;
	int	i;

	(void)argc;
	i = 1;
	while (argv[i])
	{
		if (__just_nums(argv[i]))
			return (1);
		tmp = ft_atoi(argv[i]);
		if (tmp != ft_atoi(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
