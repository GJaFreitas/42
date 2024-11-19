#include "../../headers/header.h"


void	__add_obj(t_object *o)
{
	if (!o)
		return ;
	vector(game()->objects)->add(object(o));
	if (o->func_keys != NULL)
		vector(game()->keys)->add(o);
	if (o->func_mouse != NULL)
		vector(game()->mouse)->add(o);
	if (o->render != NULL)
		vector(game()->to_render)->add(o);
	if (o->update != NULL)
		vector(game()->to_update)->add(o);
}

// Iterates trough all objects in the game and adds them to the next frame
void	__render_game()
{
	t_element	*i;
	int		in = 0;

	i = vector(game()->to_render)->begin;
	while (i)
	{
		object(i->value)->render();
		i = i->next;
		in++;
	}
}

// KEYS
void	__key_events()
{
	t_element	*i;

	i = vector(game()->keys)->begin;
	while (i)
	{
		object(i->value)->func_keys(engine()->keys);
		i = i->next;
	}
}

// MOUSE
void	__mouse_events()
{
	t_element	*i;

	i = vector(game()->mouse)->begin;
	while (i)
	{
		object(i->value)->func_mouse();
		i = i->next;
	}
	engine()->mouse_press = 0;
}

void	__destroy_objects()
{
	t_element	*i;

	i = vector(game()->objects)->begin;
	while (i)
	{
		object(i->value)->destructor();
		free_safe(&i->value);
		i = i->next;
	}
}
