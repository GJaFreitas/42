#ifndef MINITALK_H
#define MINITALK_H

#include <stdlib.h>

typedef struct s_message t_message;
typedef struct s_server t_server;

struct s_message
{
	char		*msg;
	size_t		size;
	int		pid;
	int		flag;
};

struct s_server
{
	int		count;
	size_t		c;
	unsigned char	*str;
	size_t		i;
	size_t		size;
};

#endif

/*

 client starts → calls handler with sigusr2 → client_function() call

 c = first byte → while (8) send bits and wait for akwnoledgement from
 server that bit has been processed

 when server akwnoledges the bit it does so with sigusr1 which the
 client receives and counts

 if the server has received 8 bits it sends sigusr2 and writes the
 recieved byte





*/
