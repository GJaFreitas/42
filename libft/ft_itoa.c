/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:21:32 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/10 17:22:31 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_writenum(int c, char *s)
{
	while (*s)
		s++;
	*s = c;
}

static void	ft_putnbr(int nb, char *s)
{
	char	num;

	if (nb == -2147483648)
	{
		ft_strlcpy(s, "-2147483648", 11);
		return;
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, s);
		ft_putnbr(nb % 10, s);
	}
	else
	{
		num = nb + '0';
		ft_writenum(num, s);
	}
}

static void	ft_putminus(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	s[i] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*temp;
	int	size;

	temp = ft_calloc(12, sizeof(char));
	if (n < 0)
	{
		ft_putminus(temp);
		ft_putnbr(-n, temp);
	}
	else
		ft_putnbr(n, temp);
	size = ft_strlen(temp);
	str = ft_calloc(size + 1, sizeof(char));
	ft_strlcpy(str, temp, size + 1);
	free(temp);
	return (str);
}
