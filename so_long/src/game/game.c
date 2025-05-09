/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 16:32:03 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

void		__destroy_objects(void);
void		__mouse_events(void);
void		__key_events(void);
void		__render_game(void);
void		__add_obj(t_object *o);
void		__update_game(void);
t_object	*__obj_colision(t_pos_vector pos, t_type *list);

static void	__destroy_game(void)
{
	__destroy_objects();
	vector(game()->objects)->destroy();
	vector(game()->to_update)->destroy();
	vector(game()->keys)->destroy();
	vector(game()->to_render)->destroy();
	vector(game()->mouse)->destroy();
	vector(game()->to_remove)->destroy();
}

static void	__remove_obj(void)
{
	t_element	*i;
	void		*temp;

	i = vector(game()->to_remove)->begin;
	while (i)
	{
		temp = i->value;
		vector(game()->objects)->remove_value(i->value);
		vector(game()->mouse)->remove_value(i->value);
		vector(game()->keys)->remove_value(i->value);
		vector(game()->to_update)->remove_value(i->value);
		vector(game()->to_render)->remove_value(i->value);
		vector(game()->to_remove)->remove_value(i->value);
		object(temp)->destructor();
		free_safe(&temp);
		i = vector(game()->to_remove)->begin;
	}
}

static void	__start_the_show(void)
{
	game()->in_menu = 0;
	canva()->clear_screen();
	game()->add_obj(new_bg());
	if (engine()->argc)
	{
		game()->maps[0] = new_map(engine()->argv[1]);
		game()->add_obj((t_object *)game()->maps[0]);
	}
}

void	start_game(void)
{
	game()->objects = new_vector();
	game()->keys = new_vector();
	game()->mouse = new_vector();
	game()->to_render = new_vector();
	game()->to_update = new_vector();
	game()->to_remove = new_vector();
	game()->add_obj = __add_obj;
	game()->render = __render_game;
	game()->func_keys = __key_events;
	game()->func_mouse = __mouse_events;
	game()->update = __update_game;
	game()->destructor = __destroy_game;
	game()->add_obj(new_menu());
	game()->rm_obj = __remove_obj;
	game()->obj_colision = __obj_colision;
	game()->startgame = __start_the_show;
	game()->startgame();
}

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}
