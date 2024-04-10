/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:16:44 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/10 15:54:44 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	allocpy(char **arr, char *s, char c)
{
	char	*temp;

	temp = s;
	while (*temp)
	{
		while (*s == c)
			s++;
		temp = s;
		while (*temp && *temp != c)
			temp++;
		if (*temp == c || temp > s)
		{
			*arr = ft_substr(s, 0, temp - s);
			s = temp;
			++arr;
		}
	}
	*arr = NULL;
}

static int	count_words(char const *s, char c)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			++word_count;
		while (*s && *s != c)
			++s;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int	words;

	if (!*s)
		return (NULL);
	words = count_words(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	allocpy(arr, (char *)s, c);
	return (arr);
}
