/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 14:19:46 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

// Changes the "this vector"
// another way of saying it changes the current working vector
t_vector	*vector(t_vector *vector)
{
	if (vector)
		fthis()->vector = vector;
	return (vector);
}

// Changes the "this object"
// another way of saying it changes the current working object
t_object	*object(t_object *object)
{
	if (object)
		fthis()->object = object;
	return (object);
}

t_this	*fthis(void)
{
	static t_this	this;

	return (&this);
}
