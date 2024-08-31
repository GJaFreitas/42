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
static void	__render_game()
{
	t_element	*i;

	i = vector(game()->to_render)->begin;
	while (i)
	{
		object(i->value)->render();
		i = i->next;
	}
}

static void	__key_events()
{
	t_element	*i;

	i = vector(game()->keys)->begin;
	while (i)
	{
		object(i->value)->func_keys(engine()->keys);
		i = i->next;
	}
}

static void	__mouse_events()
{
	t_element	*i;

	i = vector(game()->mouse)->begin;
	while (i)
	{
		object(i->value)->func_mouse();
		i = i->next;
	}
}

static void	__destroy_objects()
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

static void	__destroy_game(void)
{
	__destroy_objects();
	vector(game()->objects)->destroy();
	vector(game()->interactions)->destroy();
	vector(game()->keys)->destroy();
	vector(game()->to_render)->destroy();
	vector(game()->mouse)->destroy();
}

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

static void	__rm_this(t_element *e, void *v)
{
	if (e->type == *(t_type*)v)
		fthis()->vector->remove_this(e);
}

static void	__remove_obj(t_type type)
{
	t_element	*i;

	i = vector(game()->objects)->begin;
	while (i)
	{
		if (object(i->value)->type == type)
		{
			object(i->value)->destructor();
			free_safe(&i->value);
		}
		i = i->next;
	}
	vector(game()->objects)->for_each(__rm_this, &type);
	vector(game()->interactions)->for_each(__rm_this, &type);
	vector(game()->keys)->for_each(__rm_this, &type);
	vector(game()->to_render)->for_each(__rm_this, &type);
	vector(game()->mouse)->for_each(__rm_this, &type);
}

// Destroys the menu object and starts the game for real
static void	__start_the_show(void)
{
	game()->in_menu = 0;
	game()->rm_obj_type(MENU);
	game()->add_obj((t_object*)new_bg());
}

void	start_game(void)
{
	game()->objects = new_vector();
	game()->keys = new_vector();
	game()->mouse = new_vector();
	game()->to_render = new_vector();
	game()->interactions = new_vector();
	game()->add_obj = __add_obj;
	game()->render = __render_game;
	game()->func_keys = __key_events;
	game()->func_mouse = __mouse_events;
	game()->destructor = __destroy_game;
	game()->add_obj((t_object*)new_menu());
	game()->rm_obj_type = __remove_obj;
	game()->startgame = __start_the_show;
}
