/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:12:49 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/19 18:46:44 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// As should be understood this function is int to hex
// This function cannot convert the min int
static int	write_to_temp(char *temp, unsigned int num)
{
	int	hex_ascii;
	int	i;

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
		temp[i] = 0;
	}
	return (i);
}

char	*ft_itox_up(unsigned int num)
{
	char	temp[12];
	char	*ret;
	int		i;

	ft_memset(temp, 0, 12);
	i = write_to_temp(temp, num);
	if (!num)
		temp[i] = '0';
	ret = ft_revstr(temp);
	return (ret);
}
