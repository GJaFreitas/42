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

// adds all queued objects and removes them from the queue after
void	__add_queue()
{
	t_element	*i;

	i = vector(game()->to_add)->begin;
	while (i)
	{
		game()->add_obj(i->value);
		i = i->next;
	}
	vector(game()->to_render)->sort();
	vector(game()->to_add)->remove_all();
}
