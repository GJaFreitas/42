#include <signal.h>
#include "libft/libft.h"

// If the client receieves a SIGUSR1 signal it counts a byte sent and if
// it is a SIGUSR2 signal it says how many bytes were sent and exits

static void	handler(int sig)
{
	static int	count;
	static int	bits;
	
	if (sig == SIGUSR1)
	{
		bits++;
		if (bits == 8)
		{
			count++;
			bits = 0;
		}
	}
	else
	{
		ft_printf("Received: %d\n", count);
		exit(0);
	}
}

// The expression c >> 1 & 1 evaluates to 1 if the current working byte is 1
// and 0 if it is 0
//
// The rest of the explanation is on the server.c file

static void	client_function(int pid, char *message)
{
	int		i;
	unsigned char	c;
	
	while (1)
	{
		i = 8;
		c = *message;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			pause();
		}
		message++;
		if (!c)
			return ;
	}
}

// NULL message handled by ft_strlen
int	main(int argc, char **argv)
{
	if (argc != 3 || ft_strlen(argv[2]) == 0)
		return (1);
	ft_printf("To send: %d\n", ft_strlen(argv[2]));
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	client_function(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
