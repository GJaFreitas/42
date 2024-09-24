#include "../../headers/header.h"

static int	count_vec(t_type type, t_vector *vec)
{
	t_element	*i;
	int		count;

	count = 0;
	i = vec->begin;
	while (i)
	{
		if (i->type == type)
			count++;
		i = i->next;
	}
	return (count);
}

void	count_overall(t_type type)
{
	int	count;

	count = count_vec(type, vector(game()->to_render));
	count += count_vec(type, vector(game()->to_remove));
	count += count_vec(type, vector(game()->mouse));
	count += count_vec(type, vector(game()->to_update));
	count += count_vec(type, vector(game()->keys));
	ft_printf("The number of type %d is: %d\n", type, count);
	count = count_vec(type, vector(game()->objects));
	ft_printf("In the objects vector there are %d objects of type %d\n", count, type);
}
