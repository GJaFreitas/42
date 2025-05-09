#include "../philosophers.h"
#include <pthread.h>

void	standby(t_philo *p, size_t t)
{
	size_t	start;
	size_t	current;

	start = get_time();
	while (1)
	{
		current = get_time();
		if (current - p->last_eat >= p->info->death_time)
			die(p);
		if (current - start >= t)
			break ;
		usleep(10);
	}
}

// Dude eats then sleeps
void	eat(t_philo *p)
{
	pthread_mutex_lock(right_fork(p));
	pthread_mutex_lock(left_fork(p));
	pthread_mutex_lock(p->write_perm);
	print(p, "has taken a fork\n");
	print(p, "has taken a fork\n");
	p->last_eat = get_time();
	p->times_eaten++;
	print(p, "is eating\n");
	standby(p, p->info->eat_time);
	pthread_mutex_unlock(p->write_perm);
	pthread_mutex_unlock(left_fork(p));
	pthread_mutex_unlock(right_fork(p));
	a_sleep(p);
}

// Updates the 'alive' variable for all philosophers to stop the
// simulation and announces to the user the dude has died
void	die(t_philo *p)
{
	p->alive = 0;
	pthread_mutex_lock(((t_philo *)p)->write_perm);
	print(p, "died\n");
}

void	a_sleep(t_philo *p)
{
	pthread_mutex_lock(((t_philo *)p)->write_perm);
	print(p, "is sleeping\n");
	pthread_mutex_unlock(((t_philo *)p)->write_perm);
	standby(p, p->info->sleep_time);
}

void	think(t_philo *p)
{
	pthread_mutex_lock(((t_philo *)p)->write_perm);
	print(p, "is thinking\n");
	pthread_mutex_unlock(((t_philo *)p)->write_perm);
}
