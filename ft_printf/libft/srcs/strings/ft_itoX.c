/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:12:49 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/18 18:12:54 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// As should be understood this function is int to hex
// This function cannot convert the min int
char	*ft_itoX(int num)
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
	if (!num)
		temp[i] = '0';
	while (num)
	{
		hex_ascii = num % 16;
		if (hex_ascii < 10)
			hex_ascii += '0';
		else
			hex_ascii += 55;
		temp[i++] = hex_ascii;
		num = num / 16;
		temp[i] = 0;
	}
	if (sign)
		temp[i++] = '-';
	ret = ft_revstr(temp);
	return (ret);
}
