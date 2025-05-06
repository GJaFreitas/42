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

// Initializes an array of philosophers with null term
t_philo	**init_philosophers(t_philo_info *data)
{
	t_philo		**philos;
	pthread_mutex_t	**forks;
	pthread_mutex_t	*write;
	int		i;
	int		num;

	num = data->p_num;
	philos = malloc(sizeof(t_philo *) * (num + 1));
	forks = malloc(sizeof(pthread_mutex_t *) * (num + 2));
	write = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(write, NULL);
	memset(philos, 0, sizeof(t_philo *) * (num + 1));
	i = 0;
	while (i < num)
	{
		philos[i] = malloc(sizeof(t_philo));
		memset(philos[i], 0, sizeof(t_philo));
		forks[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(forks[i], NULL);
		philos[i]->write_perm = write;
		philos[i]->info = data;
		philos[i]->alive = 1;
		philos[i]->philo_index = i;
		philos[i]->forks = forks;
		i++;
	}
	forks[i] = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(forks[i], NULL);
	return (philos);
}

void	*loop(void *p)
{
	while (1)
	{
		if (left_fork(p) && right_fork(p))
			eat(p);
	}
}

int	main(int argc, char **argv)
{
	t_philo_info	data;
	t_philo		**philos;
	// unsigned int		i;

	timestamp();
	// i = 0;
	if (!parse_args(&data, argc, argv))
		return (1);
	philos = init_philosophers(&data);
	(void)philos;
	printf("%s\n", ft_itoa(47328958348957));
	// while (i < data.p_num)
	// {
	// 	pthread_create(philos[i]->thread, NULL, loop, philos[i]);
	// 	i++;
	// }
	return (0);
}
