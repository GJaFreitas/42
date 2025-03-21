/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 18:26:24 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

/*

void	*constructor(size_t size)
{
	t_object	*o;

	o = malloc_safe(size);
	o->type = OBJECT;
	o->get_sprite = __generic_get_sprite;
	o->pos.x = 0;
	o->pos.y = 0;
	return (o);
}
*/

void	__scale_img(t_sprite *img, t_pos_vector vec);

void	__generic_destructor(void)
{
	mlx_destroy_image(engine()->mlx, \
			fthis()->object->sprite->img);
	free(fthis()->object->get_sprite());
}

// Norminette is so useless
// "Too many instructions in a single line"
// and who are you to say how many instructions
// a line should have??? more than 1 is too much lol
// good luck using function pointers with these
// bogus rules
void	__generic_render(void)
{
	t_object	*obj;

	obj = fthis()->object;
	__scale_img(obj->get_sprite(), \
			obj->pos);
}

t_sprite	*__generic_get_sprite(void)
{
	return (fthis()->object->sprite);
}
