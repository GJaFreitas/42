#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	int		i;
	char	*new_str;

	i = 0;
	total_len = 0;
	while (s1[i++])
		total_len++;
	i = 0;
	while (s2[i++])
		total_len++;
	new_str = malloc(total_len + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (*(s1++))
		new_str[i++] = *s1;
	while (*(s2++))
		new_str[i++] = *s2;
	new_str[i] = 0;
	free((char *)s1);
	return (new_str);
}

char	*ft_getline(char *string, int count, int iteration)
{
	char	*ret;
	char	*str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	ret = malloc(count);
	while (string[i] && string[i] != '\n')
	{
		ret[i] = string[i];
		i++;
	}
	ret[i++] = '\n';
	ret[i] = 0;
	str = malloc((iteration * BUFFER_SIZE) - count + 1);
	while (string[i])
		str[j++] = string[i++];
	str[j] = 0;
	free(string);
	string = str;
	return (ret);
}

char    *get_line(char *string, int fd)
{
	char    buff[BUFFER_SIZE];
	char    *ret;
	int     count;
	int	iteration;

	count = 0;
	iteration = 0;
	while ((count = read(fd, buff, BUFFER_SIZE)) != 0)
	{
		iteration++;
		string = ft_strjoin(string, buff);
		while (string[count] && string[count++] != '\n');
		if (string[count - 1] == '\n')
			break ;
	}
	ret = ft_getline(string, count, iteration);
	return (ret);
}
