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
			pthread_mutex_lock(p->write_perm);
			printf("Cur: %ld\nLast eat: %ld\nStart of standbye: %ld\n", current, p->last_eat, start);
			pthread_mutex_unlock(p->write_perm);
			die(p);
			break ;
		}
		if (current - start >= t)
			break ;
		usleep(10);
	}
}

// Dude eats then sleeps
void	eat(t_philo *p)
{
	pthread_mutex_lock(p->r_fork);
	print(p, " has taken a fork\n");
	pthread_mutex_lock(p->l_fork);
	print(p, " has taken a fork\n");
	print(p, " is eating\n");
	standby(p, p->info->eat_time);
	p->last_eat = get_time();
	p->times_eaten++;
	pthread_mutex_unlock(p->l_fork);
	pthread_mutex_unlock(p->r_fork);
	a_sleep(p);
}

// Updates the 'alive' variable for all philosophers to stop the
// simulation and announces to the user the dude has died
//
// TODO: Somehow the time printed is sometimes negative
// overflow???
void	die(t_philo *p)
{
	print(p, " died\n");
	pthread_mutex_lock(p->death_check);
	*p->alive = 0;
	pthread_mutex_unlock(p->death_check);
}

void	a_sleep(t_philo *p)
{
	print(p, " is sleeping\n");
	standby(p, p->info->sleep_time);
}

void	think(t_philo *p)
{
	print(p, " is thinking\n");
}
