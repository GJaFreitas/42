#include "../../headers/header.h"

void	__update_game()
{
	t_element	*i;

	i = vector(game()->to_update)->begin;
	while (i)
	{
		object(i->value)->update();
		i = i->next;
	}
}

// Verifies if pos collides with any rendered object not part of the list
int	__obj_colision(t_pos_vector pos, t_type *list)
{
	t_element	*i;
	int		index;
	int		flag;

	index = 0;
	i = vector(game()->to_render)->begin;
	while (i)
	{
		flag = 0;
		index = 0;
		while (list[index])
			if (i->type == list[index++])
			{
				flag = 1;
				break ;
			}
		if (!flag && collides(pos, ((t_object*)(i->value))->pos))
		{
			return (1);
		}
		i = i->next;
	}
	return (0);
}
