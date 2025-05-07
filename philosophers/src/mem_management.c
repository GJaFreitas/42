#include "../philosophers.h"

// Initializes an array of philosophers with null term
t_philo	**init_philosophers(t_philo_info *data)
{
	t_philo		**philos;
	pthread_mutex_t	**forks;
	pthread_mutex_t	*write;
	int		*alive;
	int		i;
	int		num;

	num = data->p_num;
	alive = calloc(1, sizeof(int));
	*alive = 1;
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
		philos[i]->thread = calloc(1, sizeof(pthread_t));;
		philos[i]->info = data;
		philos[i]->alive = alive;
		philos[i]->philo_index = i;
		philos[i]->forks = forks;
		i++;
	}
	return (philos);
}

static void	free_philo(void *p)
{
	free(((t_philo *)p)->thread);
	free(p);
}

// Assume array is NULL terminated
static void	free_ptr_array(void **arr, void (*f)(void *))
{
	if (!arr)
		return ;
	while (*arr)
	{
		f(*arr++);
	}
}

// Cast to void ** is the most redundant thing in the world
// why doesnt the compiler do it for me?
void	free_all(t_philo **philos)
{
	free_ptr_array((void **)philos[0]->forks, free);
	free(philos[0]->forks);
	free(philos[0]->write_perm);
	free(philos[0]->alive);
	free_ptr_array((void **)philos, free_philo);
	free(philos);
}
