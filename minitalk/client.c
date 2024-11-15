#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include "minitalk.h"

// If the client receieves a SIGUSR1 signal it counts a byte sent and if
// it is a SIGUSR2 signal it says how many bytes were sent and exits

static void	client_function(void);

// The global variable
t_message	g_msg;

// SIGUSR1 means server has finished processing a bit and is ready
// for another one
//
// SIGUSR2 means the server has finished processing a byte and the next one should
// start, also client counts it has a sent char
//
// SIGUSR2 && msg == "\0" means the message has been sent

static void	handler(int sig)
{
	static int	bits;
	static int	count;

	if (sig == SIGUSR2)
	{
		bits++;
		if (bits == 8)
		{
			bits = 0;
			count++;
		}
		if (g_msg.flag)
			bits = -1;
		client_function();
	}
	else if (sig == SIGUSR1)
	{
		ft_printf("Sent %d bytes\n", count);
		exit(0);
	}
}

// The expression c >> 1 & 1 evaluates to 1 if the current working byte is 1
// and 0 if it is 0
//
// The rest of the explanation is on the server.c file

static void	send_len()
{
	static int	i = 32;

	if (g_msg.size >> --i & 1)
		kill(g_msg.pid, SIGUSR2);
	else
		kill(g_msg.pid, SIGUSR1);
	if (i == 0)
		g_msg.flag = 0;
}

static void	client_function(void)
{
	static int	i = 8;
	unsigned int	c;

	if (g_msg.flag)
		return (send_len());
	c = *g_msg.msg;
	if (c >> --i & 1)
		kill(g_msg.pid, SIGUSR2);
	else
		kill(g_msg.pid, SIGUSR1);
	if (i == 0)
	{
		i = 8;
		g_msg.msg++;
	}
}

// NULL message handled by ft_strlen
int	main(int argc, char **argv)
{
	if (argc != 3 || ft_strlen(argv[2]) == 0)
		return (1);
	g_msg.size = ft_strlen(argv[2]);
	g_msg.msg = argv[2];
	g_msg.pid = ft_atoi(argv[1]);
	g_msg.flag = 1;
	ft_printf("To send: %d\n", ft_strlen(argv[2]));
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	client_function();
	while (1)
		pause();
}
