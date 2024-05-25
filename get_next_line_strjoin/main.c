#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("argc less than 2, goodbye\n");
        return (1);
    }
	int fd = open(argv[1], O_RDONLY);
	char	*str;
    printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	while((str = get_next_line(fd)) != NULL)
    {
		printf("%s", str);
        free(str);
    }
}

