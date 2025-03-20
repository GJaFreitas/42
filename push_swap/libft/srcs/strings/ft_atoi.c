/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:23:47 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/20 17:35:55 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

long	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	long	total;

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
	}
	return (total);
}
