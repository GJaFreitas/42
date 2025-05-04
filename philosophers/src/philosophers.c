#include "../philosophers.h"
#include <stdio.h>


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

int	main(int argc, char **argv)
{
	t_philo_info	data;

	if (!parse_args(&data, argc, argv))
		return (1);
	printf("%d %d %d %d %d\n", data.p_num, data.death_time, data.eat_time, data.sleep_time, data.eat_max);
	return (0);
}
