/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:58:48 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/19 16:45:02 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen_mod(const char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str && *str == '0')
	{
		str++;
		flag = 1;
	}
	if (!str && flag)
		return (1);
	return (ft_strlen(str));
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error("Error");
		if (ft_contains(tmp, args, i))
			ft_error("Error");
		if (ft_strlen_mod(args[i]) < 1 || ft_strlen_mod(args[i]) > 11)
			ft_error("Error");
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
