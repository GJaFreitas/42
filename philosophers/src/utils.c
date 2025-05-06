#include "../philosophers.h"
#include <pthread.h>
#include <string.h>
#include <sys/time.h>

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' \
		|| c == '\v' || c == '\f' \
		|| c == ' ');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	total;

	sign = 1;
	i = 0;
	total = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = (total * 10) + (sign *(str[i++] - '0'));
	}
	return (total);
}

pthread_mutex_t	*left_fork(t_philo *p)
{
	return (p->forks[p->philo_index]);
}

pthread_mutex_t	*right_fork(t_philo *p)
{
	return (p->forks[p->philo_index + 1]);
}

size_t	ft_strlen(char *s)
{
	char *t;

	t = s;
	while (*t)
		t++;
	return (t - s);
}

static void	__itoa_recursion(size_t nb, char *s)
{
	char	num;

	if (nb > 9)
	{
		__itoa_recursion(nb / 10, s);
		__itoa_recursion(nb % 10, s);
	}
	else
	{
		num = nb + '0';
		while (*s)
			s++;
		*s = num;
	}

}

char	*ft_itoa(size_t num)
{
	size_t	cpy;
	char	*str;
	int	size;

	cpy = num;
	size = 0;
	while (cpy / 10)
	{
		cpy /= 10;
		size++;
	}
	str = malloc(size + 1);
	memset(str, 0, size);
	__itoa_recursion(num, str);
	return (str);
}

void	print(t_philo *p, char *str)
{
	int	i;
	int	j;
	char	buf[64];
	char	*time;
	char	*guy;

	time = ft_itoa(p->last_eat - timestamp());
	guy = ft_itoa(p->philo_index);
	i = 0;
	j = 0;
	while (time[j])
		buf[i++] = time[j++];
	j = 0;
	free(time);
	while (guy[j])
		buf[i++] = guy[j++];
	free(guy);
	while (*str)
		buf[i++] = *str++;
	write(1, buf, i);
}

long	timestamp(void)
{
	struct timeval	time;

	if (time.tv_sec == 0)
		gettimeofday(&time, NULL);
	return (time.tv_sec);
}
