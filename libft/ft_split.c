/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:04:16 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/08 19:25:20 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (s[i] != c && s[i + 1] != c)
		words++;
	while (s[i] != 0)
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			words++;
	}
	return (words);
}

static int	copy(char *dest, const char *src, char c)
{
	int	len;

	len = 0;
	while (*src && *src != c)
	{
		*dest = *src;
		dest++;
		src++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*temp;
	int	word_count;
	int	len;

	word_count = count_words(s, c);
	arr = ft_calloc(word_count + 1, sizeof(char *));
	temp = ft_calloc(256, sizeof(char));
	if (arr == NULL || temp == NULL)
		return (NULL);
	len = 0;
	while (word_count > 0)
	{
		len += copy(temp, s + len, c);
		*arr = ft_calloc(len + 1, sizeof(char));
		ft_strlcpy(*arr, temp, len + 1);
		arr++;
		ft_memset(temp, 0, 256);
		word_count--;
	}
	return (arr);
}
