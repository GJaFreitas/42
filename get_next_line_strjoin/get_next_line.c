#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *string;
    char    *ret;

    ret = get_line(string);
    return (ret);
}
