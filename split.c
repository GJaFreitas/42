#include <stdio.h>
#include <stdlib.h>
#include "42Lx/libft.h"

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
			printf("%s\n", *arr);
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

int	main()
{
	char	**arr = ft_split("Eu consigo, lets go", ' ');
	int	i = 0;

	while (arr[i])
	{
		printf("string[%d]: %s\n", i, arr[i]);
		i++;
	}
}
