#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// Eat max is optional and if not given stays at 0
typedef struct s_philosophers
{
	unsigned int	p_num;
	unsigned int	death_time;
	unsigned int	eat_time;
	unsigned int	sleep_time;
	unsigned int	eat_max;
}	t_philo_info;

int	ft_atoi(const char *str);

#endif
