#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>

// Eat max is optional and if not given stays at 0
typedef struct s_philosophers
{
	size_t	p_num;
	size_t	death_time;
	size_t	eat_time;
	size_t	sleep_time;
	size_t	eat_max;
}	t_philo_info;

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

int		ft_atoi(const char *str);
void	eat(t_philo *p);
void	die(t_philo *p);
void	think(t_philo *p);
void	a_sleep(t_philo *p);
int	can_eat(t_philo *p);
char	*ft_itoa(size_t num);
size_t	get_time(void);
void	free_all(t_philo **philos);
t_philo	**init_philosophers(t_philo_info *data, pthread_mutex_t ***forks);

void	print(t_philo *p, char *str);
int	check_dead(t_philo *p);
void	free_ptr_array(void **arr, void (*f)(void *));
void	destroy_mutex(void *mutex);


// Get the timestamp from when the program started
size_t	timestart(void);

#endif
