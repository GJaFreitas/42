#include "../philosophers.h"
#include <pthread.h>

/*
• Each philosopher must be represented as a separate thread.

• There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, they will have access to just one fork.

• To prevent philosophers from duplicating forks, you should protect each fork’s state
with a mutex.
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

void	*the_thinker(void *p)
{
	if (((t_philo *)p)->philo_index % 2)
		usleep(20);
	while (729)
	{
		eat(p);
		if (((t_philo *)p)->info->eat_max \
		&& ((t_philo *)p)->times_eaten == ((t_philo *)p)->info->eat_max)
			break ;
		if (!((t_philo *)p)->alive)
			break ;
		think(p);
		if (!((t_philo *)p)->alive)
			break ;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philo_info	data;
	t_philo		**philos;
	unsigned int		i;

	i = 0;
	if (!parse_args(&data, argc, argv))
		return (1);
	philos = init_philosophers(&data);
	timestamp();
	while (i < data.p_num)
	{
		pthread_create(philos[i]->thread, NULL, the_thinker, philos[i]);
		i++;
	}
	pthread_mutex_unlock(philos[0]->write_perm);
	free_all(philos);
	return (0);
}
