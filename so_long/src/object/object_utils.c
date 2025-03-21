/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 14:19:47 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

/*
struct s_object
{
	t_type			type;
	t_vector		pos;
	double			hp;
	t_sprite		*sprite;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_key)(t_object*);
	void			(*func_mouse)(t_object*);
	void			(*set_pos)(t_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();
};
*/
void		__generic_destructor(void);
void		__generic_render(void);
t_sprite	*__generic_get_sprite(void);

// Returns a new instance of an object with variable size
void	*constructor(size_t size)
{
	t_object	*o;

	o = malloc_safe(size);
	o->type = OBJECT;
	o->func_keys = NULL;
	o->func_mouse = NULL;
	o->update = NULL;
	o->render = __generic_render;
	o->get_sprite = __generic_get_sprite;
	o->destructor = __generic_destructor;
	return (object(o));
}
