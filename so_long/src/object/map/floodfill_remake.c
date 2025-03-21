/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_remake.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 14:19:47 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/header.h"

/*
void	__display_map_debug(const t_map *s_map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < s_map->row)
	{
		while (x < s_map->col)
		{
			ft_printf("%c", s_map->map_ptr[y][x]);
			x++;
		}
		ft_printf("\n");
		x = 0;
		y++;
	}
}
*/

void	__flood_fill_r(t_map *s_map, int x, int y)
{
	if (s_map->map_ptr[y][x] == 'E')
		s_map->error[7] = 0;
	if (s_map->map_ptr[y][x] == 'C')
		s_map->hp++;
	if (s_map->hp == s_map->collectible_num)
		s_map->error[8] = 0;
	s_map->map_ptr[y][x] = '1';
	if (y < s_map->row && s_map->map_ptr[y + 1][x] != '1')
		__flood_fill_r(s_map, x, y + 1);
	if (x < s_map->col && s_map->map_ptr[y][x + 1] != '1')
		__flood_fill_r(s_map, x + 1, y);
	if (y > 0 && y < s_map->row && s_map->map_ptr[y - 1][x] != '1')
		__flood_fill_r(s_map, x, y - 1);
	if (x > 0 && x < s_map->col && s_map->map_ptr[y][x - 1] != '1')
		__flood_fill_r(s_map, x - 1, y);
}
