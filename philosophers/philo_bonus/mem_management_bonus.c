#include "philosophers_bonus.h"

/*

typedef struct s_philo
{
	int		*alive;
	size_t		philo_index;
	size_t		times_eaten;
	size_t		last_eat;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_perm;
	pthread_mutex_t	*death_check;
	pthread_t	*thread;
	t_philo_info	*info;
}	t_philo;

*/

pthread_mutex_t	**init_forks(int num)
{
	pthread_mutex_t	**forks;
	int	i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t *) * (num + 1));
	memset(forks, 0, sizeof(pthread_mutex_t *) * (num + 1));
	while (i < num)
	{
		forks[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(forks[i], NULL);
		i++;
	}
	return (forks);
}

typedef struct s_perms
{
	pthread_mutex_t	*write;
	pthread_mutex_t	*death_check;
}	t_perms;

int	*init_perms(t_perms *perms)
{
	int	*alive;

	alive = malloc(sizeof(int));
	*alive = 1;
	perms->write = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(perms->write, NULL);
	perms->death_check = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(perms->death_check, NULL);
	return (alive);
}

t_philo	**alloc_filos(int num)
{
	t_philo	**philos;
	int	i;

	i = 0;
	philos = malloc((num + 1) * sizeof(t_philo *));
	memset(philos, 0, sizeof(t_philo *) * (num + 1));
	while (i < num)
	{
		philos[i] = malloc(sizeof(t_philo));
		memset(philos[i], 0, sizeof(t_philo));
		philos[i]->thread = malloc(sizeof(pthread_t));
		philos[i]->philo_index = i + 1;
		i++;
	}
	return (philos);
}

void	assign_fork(t_philo *p, pthread_mutex_t **forks)
{
	p->r_fork = forks[p->philo_index - 1];
	if (p->philo_index != p->info->p_num)
		p->l_fork = forks[p->philo_index];
	else
		p->l_fork = forks[0];
}

// Initializes an array of philosophers with null term and the mutex array 'forks'
t_philo	**init_philosophers(t_philo_info *data, pthread_mutex_t ***forks)
{
	t_philo		**philos;
	t_perms		perms;
	size_t		i;
	int		*alive;

	i = 0;
	*forks = init_forks(data->p_num);
	alive = init_perms(&perms);
	philos = alloc_filos(data->p_num);
	while (i < data->p_num)
	{
		philos[i]->info = data;
		philos[i]->write_perm = perms.write;
		philos[i]->death_check = perms.death_check;
		philos[i]->alive = alive;
		assign_fork(philos[i], *forks);
		i++;
	}
	return (philos);
}

static void	free_philo(void *p)
{
	free(((t_philo *)p)->thread);
	free(p);
}

void	destroy_mutex(void *mutex)
{
	pthread_mutex_destroy(mutex);
	free(mutex);
}

// Assume array is NULL terminated
void	free_ptr_array(void **arr, void (*f)(void *))
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
	free(philos[0]->death_check);
	free(philos[0]->write_perm);
	free(philos[0]->alive);
	free_ptr_array((void **)philos, free_philo);
	free(philos);
}
