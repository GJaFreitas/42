#include "../../headers/header.h"

/*
struct s_game
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_key)(t_object*);
	void			(*func_mouse)(t_object*);
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();

	void			*objects;
	void			*keys;
	void			*to_render;
	void			*interactions;
	void			(*start)();
};
*/
void	__add_obj(t_object *o);

// Iterates trough all objects in the game and adds them to the next frame
void	__render_game(t_canva *canva)
{
	t_element	*i;

	i = vector(game()->to_render)->begin;
	while (i)
	{
		object(i->value);
		fthis()->object->render(canva);
		i = i->next;
	}
}

void	__destroy_game(void)
{
	vector(game()->objects)->destroy();
	vector(game()->interactions)->destroy();
	vector(game()->keys)->destroy();
	vector(game()->to_render)->destroy();
}

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

void	start_game(void)
{
	game()->in_menu = 1;		
	game()->objects = new_vector();
	game()->keys = new_vector();
	game()->to_render = new_vector();
	game()->interactions = new_vector();
	game()->add_obj = __add_obj;
	game()->add_obj((t_object*)new_menu);
}
