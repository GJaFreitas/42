/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:13:29 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/19 15:32:01 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft.h"

char	*ft_itoptr(size_t num)
{
	char	temp[16];
	char	*ret;
	int		i;
	int		hex_ascii;

	ft_memset(temp, 0, 12);
	i = 0;
	if (!num)
		return (ft_strdup("(nil)"));
	while (num)
	{
		hex_ascii = num % 16;
		if (hex_ascii < 10)
			hex_ascii += '0';
		else
			hex_ascii += 87;
		temp[i++] = hex_ascii;
		num = num / 16;
	}
	temp[i++] = 'x';
	temp[i++] = '0';
	temp[i] = 0;
	ret = ft_revstr(temp);
	return (ret);
}
