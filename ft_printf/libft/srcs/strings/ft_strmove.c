/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:37:21 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/18 12:37:47 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft.h"

// required for ft_printf, unsafe as hell. assumes there is space in the buffer
int	ft_strmove(char *dest, char *src)
{
	int	count;

	count = 0;
	while (src[count])
	{
		dest[count] = src[count];
		count++;
	}
	free(src);
	return (count);
}
