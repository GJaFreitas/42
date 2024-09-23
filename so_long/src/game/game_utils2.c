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

// Verifies if pos collides with any rendered object
int	__obj_colision(t_pos_vector pos)
{
	t_element	*i;

	i = vector(game()->to_render)->begin;
	while (i)
	{
		if (collides(pos, object(i->value)->pos))
			return (1);
		i = i->next;
	}
	return (0);
}
