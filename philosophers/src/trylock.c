#include "../philosophers.h"
#include <pthread.h>

/*
       The pthread_mutex_unlock() function shall release the mutex object
       referenced by mutex.  The manner in which a mutex is released is
       dependent upon the mutex's type attribute. If there are threads
       blocked on the mutex object referenced by mutex when
       pthread_mutex_unlock() is called, resulting in the mutex becoming
       available, the scheduling policy shall determine which thread
       shall acquire the mutex.

 */
static void	*wait_until_lock(void *ptr)
{
	pthread_mutex_t	*mutex;
	int		*condition;

	mutex = ((t_trylock *)ptr)->mutex;
	condition = ((t_trylock *)ptr)->cond;

	pthread_mutex_lock(mutex);
	*condition = 1;

	return (NULL);
}


/*
 * Attempt to lock a mutex;
 * 'time' is the max time in ms allowed for the attempt;
*/
int	trylock(t_trylock *tl, unsigned long time)
{
	pthread_t	thread;
	size_t	start;
	size_t	current;
	int		condition;
	pthread_mutex_t	*mutex = tl->mutex;

	start = get_time();
	pthread_create(&thread, NULL, wait_until_lock, &(t_trylock){NULL, mutex, &condition});
	while (1)
	{
		current = get_time();
		if (current - start > time)
			return (0);
		if (condition)
			return (1);
		usleep(10);
	}
	pthread_join(thread, NULL);
}
