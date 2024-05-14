#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static t_data *data;
    t_data *temp;
    char    *ret;
    int     i;

    i = 0;
    temp = data;
    if (temp == NULL)
    {
        temp = malloc(sizeof(t_data));
        temp->leftover = malloc(1);
        *(temp->leftover) = 0;
        temp->size = 0;
    }
    while (temp->leftover[i] && temp->leftover[i] != '\n')
        i++;
    if (temp->leftover[i] == '\n')
        ret = ft_getline(temp, i);
    else
        ret = read_line(temp, fd);
    return (ret);
}
