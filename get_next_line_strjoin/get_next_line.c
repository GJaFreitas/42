#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static t_data *data;
    t_data *temp;
    char    *ret;
    int     i;

    i = 0;
    if (data == NULL)
    {
        data = malloc(sizeof(t_data));
        data->leftover = malloc(1);
        *(data->leftover) = 0;
        data->size = 1;
    }
    temp = data;
    while (temp->leftover[i] && temp->leftover[i] != '\n')
        i++;
    if (temp->leftover[i] == '\n')
        ret = ft_getline(temp, i + 1);
    else
        ret = read_line(temp, fd);
    return (ret);
}
