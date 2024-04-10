/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:40:55 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/10 17:54:56 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//not entirely sure this is correct
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	cont;

	i = 0;
	j = 0;
	cont = 0;
	while (dst[i] != 0)
	{
		cont++;
		i++;
	}
	while (src[j] != 0 && j < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	while (i++ < size)
	{
		dst[i] = 0;
	}
	return (ft_strlen((char *) dst) + ft_strlen((char *) src));
}
