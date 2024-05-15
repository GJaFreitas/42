#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int main()
{
	int fd = open("testfile.txt", O_RDONLY);
	char	*str;
	while((str = get_next_line(fd)) != NULL)
    {
		printf("%s", str);
        free(str);
    }
}

