/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:16:44 by gjacome-          #+#    #+#             */
/*   Updated: 2024/08/19 15:16:03 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	destroy(char ***arr)
{
	int	i;

	i = 0;
	while (**arr != NULL)
	{
		free(*arr[i]);
		i++;
	}
	*arr = NULL;
}

static void	allocpy(char **arr, char *s, char c)
{
	char	*temp;
	char	**arr_cpy;

	temp = s;
	arr_cpy = arr;
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
			if (*arr == NULL)
				return (destroy(&arr_cpy));
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
	int		words;

	if (!*s)
	{
		arr = malloc(sizeof(char *));
		if (!arr)
			return (NULL);
		*arr = NULL;
		return (arr);
	}
	words = count_words(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	allocpy(arr, (char *)s, c);
	return (arr);
}
