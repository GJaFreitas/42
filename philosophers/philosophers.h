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
	unsigned int	p_num;
	unsigned int	death_time;
	unsigned int	eat_time;
	unsigned int	sleep_time;
	unsigned int	eat_max;
}	t_philo_info;

typedef struct s_philo
{
	int		philo_index;
	int		alive;
	int		times_eaten;
	time_t		last_eat;
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

// Usleep wrapper to get time in ms instead of microseconds
void	wusleep(useconds_t t);



// Get the timestamp from when the program started
long	timestamp(void);

#endif
