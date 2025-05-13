#include "philosophers.h"

int	check_dead(t_philo *p)
{
	int	var;

	pthread_mutex_lock(p->death_check);
	var = *p->alive;
	pthread_mutex_unlock(p->death_check);
	return (!var);
}

void	standby(t_philo *p, size_t t)
{
	size_t	start;
	size_t	current;

	start = get_time();
	while (1)
	{
		current = get_time();
		if (current - p->last_eat >= p->info->death_time)
		{
			die(p);
			break ;
		}
		if (current - start >= t)
			break ;
		usleep(10);
	}
}
