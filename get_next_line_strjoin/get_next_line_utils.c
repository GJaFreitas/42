#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	int		i;
	char	*new_str;

    i = 0;
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
	return (new_str);
}

char    *get_line(char *string, int fd)
{
    char    buff[BUFFER_SIZE];
    char    *ret;
    int     count;

    while ((count = read(fd, buff, BUFFER_SIZE)) != 0)
    {
        string = ft_strjoin(string, buff);
    }
    return (ret);
}
