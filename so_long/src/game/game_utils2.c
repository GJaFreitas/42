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
