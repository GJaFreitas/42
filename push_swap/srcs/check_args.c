/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:37:18 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/20 19:37:20 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

static int	__just_nums(const char *str)
{
	int	i;

	i = 0;
	while (str && (!ft_isdigit(*str) || *str == 0))
		str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_mod(const char *str)
{
	while (str && (!ft_isdigit(*str) || *str == 0))
		str++;
	return (ft_strlen(str));
}

int	ft_check_args(int argc, char **argv)
{
	long	tmp;
	int		i;

	(void)argc;
	i = 1;
	while (argv[i])
	{
		if (__just_nums(argv[i]))
			return (1);
		tmp = ft_atoi(argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}
