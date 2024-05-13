#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *string;
    char    *ret;
    char    *temp;

    temp = string;
    if (string == NULL)
    {
	    string = malloc(1);
	    *string = 0;
    }
    ret = get_line(temp, fd);
    return (ret);
}
