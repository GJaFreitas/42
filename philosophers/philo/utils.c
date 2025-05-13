#include "philosophers.h"

void	print(t_philo *p, char *str)
{
	if (!check_dead(p))
	{
		pthread_mutex_lock(p->write_perm);
		printf("%ld %ld %s", get_time(), p->philo_index, str);
		pthread_mutex_unlock(p->write_perm);
	}
}

// The time at the start of the simulation in ms
size_t	timestart(void)
{
	static struct timeval	time;

	if (time.tv_sec == 0)
		gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

// TODO: God fucking dammit this piece of shit is
// overflowing what the fuck
// The current time in ms
size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)) - timestart());
}
