/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:17:47 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/25 18:55:47 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

float	scale_to(int w, int h)
{
	float	scale_factor;

	if (w > h)
	{
		scale_factor = (float)WIDTH_W / w;
	}
	else
	{
		scale_factor = (float)HEIGHT_W / h;
	}
	return (scale_factor);
}
