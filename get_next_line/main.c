#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);

	(void) argc;
	char *s = get_next_line(fd);
	printf("%s", s);
}
