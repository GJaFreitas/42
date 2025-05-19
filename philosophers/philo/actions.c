#include "philosophers.h"

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
void	die(t_philo *p)
{
	pthread_mutex_lock(p->death_check);
	if (*p->alive)
		printf("%ld %ld died\n", get_time(), p->philo_index);
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
