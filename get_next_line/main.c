#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int main()
{
	int fd = open("testfile.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}

