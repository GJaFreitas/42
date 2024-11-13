#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>

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

static void	handler(int sig, siginfo_t *info, void *context)
{
	static int		count;
	static unsigned char	c;

	(void)context;
	c |= (sig == SIGUSR2);
	if (++count == 8)
	{
		count = 0;
		if (!c)
		{
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
	else
		c <<= 1;
	kill(info->si_pid, SIGUSR1);
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
