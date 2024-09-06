#include "../../headers/header.h"

void	__destroy_objects();
void	__mouse_events();
void	__key_events();
void	__render_game();
void	__add_obj(t_object *o);

static void	__destroy_game(void)
{
	__destroy_objects();
	vector(game()->objects)->destroy();
	vector(game()->interactions)->destroy();
	vector(game()->keys)->destroy();
	vector(game()->to_render)->destroy();
	vector(game()->mouse)->destroy();
	vector(game()->to_remove)->destroy();
}

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

static void	__remove_obj()
{
	t_element	*i;
	void		*temp;

	i = vector(game()->to_remove)->begin;
	while (i)
	{
		vector(game()->objects)->remove_value(i->value);
		vector(game()->mouse)->remove_value(i->value);
		vector(game()->keys)->remove_value(i->value);
		vector(game()->interactions)->remove_value(i->value);
		vector(game()->to_render)->remove_value(i->value);
		object(i->value)->destructor();
		temp = i->value;
		vector(game()->to_remove)->remove_value(temp);
		free_safe(&temp);
		i = vector(game()->to_remove)->begin;
	}
}

// Destroys the menu object and starts the game for real
static void	__start_the_show(void)
{
	game()->in_menu = 0;
	game()->add_obj(new_bg());
	game()->add_obj((t_object*)game()->maps[0]);
	game()->add_obj(new_player(PLAYER));
}

void	start_game(void)
{
	game()->objects = new_vector();
	game()->keys = new_vector();
	game()->mouse = new_vector();
	game()->to_render = new_vector();
	game()->interactions = new_vector();
	game()->to_remove = new_vector();
	game()->add_obj = __add_obj;
	game()->render = __render_game;
	game()->func_keys = __key_events;
	game()->func_mouse = __mouse_events;
	game()->destructor = __destroy_game;
	game()->add_obj(new_menu());
	game()->rm_obj = __remove_obj;
	game()->startgame = __start_the_show;
}
