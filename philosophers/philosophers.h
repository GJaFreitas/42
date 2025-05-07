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
	pthread_mutex_t	**forks;
	pthread_mutex_t	*write_perm;
	pthread_t	*thread;
	t_philo_info	*info;
}	t_philo;

int		ft_atoi(const char *str);
pthread_mutex_t	*right_fork(t_philo *p);
pthread_mutex_t	*left_fork(t_philo *p);
void	eat(t_philo *p);
void	die(t_philo *p);
void	think(t_philo *p);
void	a_sleep(t_philo *p);
int	can_eat(t_philo *p);
char	*ft_itoa(size_t num);
size_t	get_time(void);
void	free_all(t_philo **philos);
t_philo	**init_philosophers(t_philo_info *data);

// Usleep wrapper to get time in ms instead of microseconds
void	wusleep(useconds_t t);

void	print(t_philo *p, char *str);


// Get the timestamp from when the program started
size_t	timestamp(void);

#endif
