/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 15:44:17 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

void	__update_game(void)
{
	t_element	*i;

	i = vector(game()->to_update)->begin;
	while (i)
	{
		object(i->value)->update();
		i = i->next;
	}
}

// Verifies if pos collides with any rendered
// object part of the list passed to it
t_object	*__obj_colision(t_pos_vector pos, t_type *list)
{
	t_element	*i;
	int			index;
	int			flag;

	index = 0;
	i = vector(game()->to_render)->begin;
	while (i)
	{
		flag = 1;
		index = 0;
		while (list && list[index])
		{
			if (i->type == list[index++])
			{
				flag = 0;
				break ;
			}
		}
		if (!flag && collides(pos, ((t_object *)(i->value))->pos))
		{
			return (i->value);
		}
		i = i->next;
	}
	return (NULL);
}
