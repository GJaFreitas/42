/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 15:41:43 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	__render_game(void)
{
	t_element	*i;

	i = vector(game()->to_render)->begin;
	while (i)
	{
		object(i->value)->render();
		i = i->next;
	}
}

// KEYS
void	__key_events(void)
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
void	__mouse_events(void)
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

void	__destroy_objects(void)
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
