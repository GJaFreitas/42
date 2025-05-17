#include "philosophers_bonus.h"
#include <pthread.h>

/*
The kill() system call can be used to send any signal to any
       process group or process.

       If pid is positive, then signal sig is sent to the process with
       the ID specified by pid.

       If pid equals 0, then sig is sent to every process in the process
       group of the calling process.

       If pid equals -1, then sig is sent to every process for which the
       calling process has permission to send signals, except for process
       1 (init), but see below.

*/

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

void	*loop(void *ptr)
{
	t_philo	*p;

	p = ptr;
	if (p->philo_index % 2)
		usleep(100);
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
	t_philo_info	data;
	t_philo		**philos;
	pthread_mutex_t	**forks;
	unsigned int		i;

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
	pthread_mutex_unlock(philos[0]->write_perm);
	free_ptr_array((void **)forks, destroy_mutex);
	free_all(philos);
	return (0);
}
