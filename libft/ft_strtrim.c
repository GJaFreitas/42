/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:50:02 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/08 19:33:07 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	trim_it(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i] != 0)
	{
		str[i] = str[j];
		i++;
		j++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int	i;
	int	j;

	trimmed = malloc(ft_strlen((char *)s1));
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, s1, ft_strlen((char *)s1));
	i = 0;
	while (trimmed[i] != 0)
	{
		j = 0;
		while (trimmed[i] != set[j] && set[j] != 0)
			j++;
		if (trimmed[i] == set[j])
			trim_it(trimmed + i);
	}
	return (trimmed);
}
