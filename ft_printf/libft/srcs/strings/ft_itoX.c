/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:12:49 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/18 12:13:31 by gjacome-         ###   ########.fr       */
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

	ft_memset(temp, 0, 12);
	if (num < 0)
	{
		sign = 1;
		num *= -1;
	}
	i = 0;
	while (num)
	{
		temp[i] = "0123456789ABCDEF"[num % 16] - '0';
		num = num / 16;
		i++;
	}
	if (sign)
		temp[i] = '-';
	ret = ft_revstr(temp);
	return (ret);
}
