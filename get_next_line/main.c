#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int fd = 0;

	char *s = get_next_line(fd);
	printf("%s", s);
}
