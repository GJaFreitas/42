#include "philosophers.h"
#include <pthread.h>

int	parse_args(t_philo_info *data, int argc, char **argv)
{
	if (argc < 5)
		return (0);
	data->p_num = ft_atoi(argv[1]);
	data->death_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data->eat_max = ft_atoi(argv[5]);
	else
		data->eat_max = 0;
	return (1);
}

// usleep(x) is dependant on hardware, in 42 computers 100 works
// while on my laptop 100 leads to unpredictable outcomes 200
// will make it so around 95% of the time the code works as it should
// but sometimes, very rarely it does something different.
// THIS IS DEPENDANT ON HOW MANY PROGRAMS IM USING AT THE TIME
// it feels like given enough time any test, even the "impossible to
// fail" ones will fail
void	*loop(void *ptr)
{
	// static size_t	i;
	t_philo	*p;

	p = ptr;
	// pthread_mutex_lock(((t_philo *)ptr)->write_perm);
	// i++;
	// pthread_mutex_unlock(((t_philo *)ptr)->write_perm);
	// while (1)
	// 	if (i == ((t_philo *)ptr)->info->p_num)
	// 		break ;
	if (p->philo_index % 2)
		usleep(300);
	while (729)
	{
		eat(p);
		if (p->info->eat_max \
		&& p->times_eaten == p->info->eat_max)
			break ;
		if (check_dead(p))
			break ;
		think(p);
		if (check_dead(p))
			break ;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_mutex_t	**forks;
	t_philo_info	data;
	unsigned int	i;
	t_philo			**philos;

	i = 0;
	if (!parse_args(&data, argc, argv))
		return (1);
	philos = init_philosophers(&data, &forks);
	timestart();
	while (i < data.p_num)
	{
		pthread_create(philos[i]->thread, NULL, loop, philos[i]);
		i++;
	}
	i = 0;
	while (i < data.p_num)
	{
		pthread_join(*philos[i]->thread, NULL);
		i++;
	}
	free_ptr_array((void **)forks, destroy_mutex);
	free_all(philos);
	return (0);
}
