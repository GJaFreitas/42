/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:17:47 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 15:12:27 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

t_byte	__draw_pixel(int x, int y, int color);

void	__clear_screen(void)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT_W)
	{
		x = 0;
		while (x < WIDTH_W)
		{
			__draw_pixel(x, y, 0);
			x++;
		}
		y++;
	}
}
