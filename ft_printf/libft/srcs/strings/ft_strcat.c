/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:36:10 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/17 18:38:54 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft.h"

int	ft_strcat(char *dst, const char *src)
{
	int	i;
	int	j;
	int	dstsize;

	i = 0;
	dstsize = ft_strlen(dst);
	j = dstsize + 1;
	while (src[i] && i < dstsize)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = 0;
	return (j);
}
