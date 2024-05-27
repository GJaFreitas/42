#include "get_next_line.h"

void    ft_strjoin(t_data *data, char const *s2)
{
    char    *new_str;
    char    *temp;
    int     i;
    int     j;

    i = 0;
    j = 0;
    temp = data->leftover;
    new_str = malloc(data->size + 1);
    while (data->leftover[i])
    {
        new_str[i] = data->leftover[i];
        i++;
    }
    while (i < data->size)
        new_str[i++] = s2[j++];
    new_str[i] = 0;
    data->leftover = new_str;
    free(temp);
}

void    ft_parsestr(t_data *data, int size)
{
    char    *new_str;
    int     i;
    int     j;

    i = 0;
    j = 0;
    new_str = malloc(size + 1);
    while (data->leftover[i] && data->leftover[i] != '\n')
        i++;
    i++;
    while (data->leftover[i])
    {
        new_str[j] = data->leftover[i];
        i++;
        j++;
    }
    new_str[j] = 0;
    free(data->leftover);
    data->leftover = new_str;
    data->size = size;
}

// TODO
// Empty line - flag == \n
// EOF
// Problem: if data->leftover = "c\0" and count is 0 it will count
// as EOF, since there is no \n in the end and the file as been
// read already. I need to find a way to go around this
// Perhaps on the ft_getline function?
char    *ft_edge_case(t_data *data, int flag)
{
    char    *ret;

    if (flag == '\n')
    {
        ret = malloc(2);
        ret[0] = '\n';
        ret[1] = 0;
        ft_parsestr(data, data->size - 0);
        return (ret);
    }
    else
    {
        free(data->leftover);
        free(data);
        return (NULL);
    }
}

char	*ft_getline(t_data *data, int count)
{
    char	*ret;
    int	    i;

    if (count == 0)
        return (ft_edge_case(data, (int)data->leftover[0]));
    i = 0;
    ret = malloc(count + 1);
    while (i < count)
    {
        ret[i] = data->leftover[i];
        i++;
    }
    ret[i] = 0;
    ft_parsestr(data, data->size - count);
    return (ret);
}

char    *read_line(t_data *data, int fd)
{
    char    buff[BUFFER_SIZE + 1];
    char    *ret;
    int     bytes_read;
    int     count;

    count = 0;
    while ((bytes_read = read(fd, buff, BUFFER_SIZE)) != 0)
    {
        if (bytes_read == -1)
            return (NULL);
        buff[bytes_read] = 0;
        data->size += bytes_read;
        ft_strjoin(data, buff);
        while (data->leftover[count] && data->leftover[count++] != '\n');
        if (data->leftover[count - 1] == '\n')
            break ;
    }
    ret = ft_getline(data, count);
    return (ret);
}
