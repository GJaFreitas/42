#include "libft/libft.h"
#include "minitalk.h"
#include <unistd.h>
#include <signal.h>

// SIGUSR1 means server has finished processing a bit and is ready
// for another one
//
// SIGUSR2 means the server has finished processing a byte and the next one should
// start, also client counts it has a sent char
//
// SIGUSR2 && msg == "\0" means the message has been sent
//
// ******************************************************
//
// If sig == SIGUSR2 then the least significant bit of c is set to 1
// This happens 8 times and everytime c is shifted to the left
// This way using only 1's and 0's we can get a byte from the client
//
// When c has been completed and has 8 bits we print the character it makes
// and set it back to 0 to ready up for more processing, we also send a signal
// to the client telling it a full byte has been received
//
// If the byte we recieved is set to all 0's then we send a signal to the client
// to make it exit since the whole message has been received


/*
static void	debug(t_server s)
{
	ft_printf("\n\nDEBUG:\nstr > %s\ncount > %d\nc > %d\ni > %d\nsize > %d\n\n", s.str, s.count, s.c, s.i, s.size);
}
*/

static void	size_received(t_server *s)
{
	s->str = malloc(s->c);
	s->size = s->c;
	s->count = 0;
	s->c = 0;
}

static void	byte_received(t_server *s)
{
	write(1, s->str, s->size);
	free(s->str);
	s->i = 0;
	s->str = NULL;
}

static void	handler(int sig, siginfo_t *info, void *context)
{
	static t_server	s;

	(void)context;
	s.c |= (sig == SIGUSR2);
	if (!s.str && ++s.count == 32)
		size_received(&s);
	else if (s.str && ++s.count == 8)
	{
		s.count = 0;

		s.str[s.i++] = s.c;
		if (!s.c)
		{
			byte_received(&s);
			kill(info->si_pid, SIGUSR1);
			return ;
		}
		s.c = 0;
	}
	else
		s.c <<= 1;
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("Server PID: %d\n", getpid());
	sig.sa_sigaction = handler;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}
