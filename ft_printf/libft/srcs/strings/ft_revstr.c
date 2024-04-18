/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:04:09 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/18 12:25:26 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// Function that returns a pointer to a reversed string
char	*ft_revstr(char *str)
{
	int	size;
	int	i;
	char	*revstr;

	size = ft_strlen(str);
	revstr = malloc(size + 1);
	revstr[size] = 0; // Null terminating str
	i = 0;
	size--;
	while (i < size)
	{
		revstr[i] = str[size];
		i++;
		size--;
	}
	return (revstr);
}
