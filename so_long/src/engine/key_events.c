/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/25 14:27:19 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

int	__key_press(int key, void *engine)
{
	if (key == XK_Escape)
		harbinger_of_chaos();
	if (!((t_engine *)engine)->keys[key])
		((t_engine *)engine)->keys_pressed++;
	((t_engine *)engine)->keys[key] = 1;
	return (0);
}

int	__key_release(int key, void *engine)
{
	if (((t_engine *)engine)->keys[key])
		((t_engine *)engine)->keys_pressed--;
	((t_engine *)engine)->keys[key] = 0;
	return (0);
}
