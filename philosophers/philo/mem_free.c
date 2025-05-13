#include "philosophers.h"

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
