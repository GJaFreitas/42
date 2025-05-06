#include "../philosophers.h"
#include <pthread.h>


void	standby(t_philo *p, useconds_t t)
{
	usleep(t * 1000);
}

int	can_eat(t_philo *p)
{
	if (left_fork(p) && right_fork(p))
		return (1);
	return (0);
}

void	eat(t_philo *p)
{
	struct timeval	time;
	struct timezone	tz;

	gettimeofday(&time, &tz);
	pthread_mutex_lock(left_fork(p));
	pthread_mutex_lock(right_fork(p));
	p->last_eat = time.tv_sec;
	p->times_eaten++;
	pthread_mutex_lock(p->write_perm);
	printf("%ldms %d is eating\n", time.tv_sec, p->philo_index);
	pthread_mutex_unlock(p->write_perm);
	pthread_mutex_unlock(left_fork(p));
	pthread_mutex_unlock(right_fork(p));
	// a_sleep(p);
}

// void	a_sleep(t_philo *p)
// {
// 	wusleep(p->info->sleep_time);
// }

// void	think(t_philo *p)
// {
// }
