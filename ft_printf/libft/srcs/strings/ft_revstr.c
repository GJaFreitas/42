/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:04:09 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/19 15:32:07 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// Function that returns a pointer to a reversed string
char	*ft_revstr(char *str)
{
	int		size;
	int		i;
	int		j;
	char	*revstr;

	size = ft_strlen(str);
	revstr = malloc(size + 1);
	revstr[size] = 0;
	i = 0;
	j = size - 1;
	while (i < size)
	{
		revstr[i] = str[j];
		i++;
		j--;
	}
	return (revstr);
}
