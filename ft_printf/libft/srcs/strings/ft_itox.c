/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:52:09 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/18 12:49:58 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// As should be understood this function is int to hex
// This function cannot convert the min int
char	*ft_itox(int num)
{
	char	temp[12];
	char	*ret;
	int	i;
	int	sign;
	int	hex_ascii;

	ft_memset(temp, 0, 12);
	if (num < 0)
	{
		sign = 1;
		num *= -1;
	}
	i = 0;
	while (num)
	{
		hex_ascii = num % 16;
		if (hex_ascii < 10)
			hex_ascii += '0';
		else
			hex_ascii += 55;
		temp[i++] = hex_ascii;
		num = num / 16;
	}
	if (sign)
		temp[i] = '-';
	ret = ft_revstr(temp);
	return (ret);
}
