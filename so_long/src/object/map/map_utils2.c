/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/25 18:08:31 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/header.h"

void	__map_handler(char c, t_map *s_map, t_pos_vector pos);
t_byte	__check_walls(t_map *s_map);

// Checks if there is an exit, a start and at least 1 collectible
void	__check_components(t_map *s_map)
{
	if (s_map->start.x == 0)
		s_map->error[2] = 1;
	if (s_map->exit.x == 0)
		s_map->error[3] = 1;
	if (!count_obj(COLLECTIBLE))
		s_map->error[6] = 1;
}

// returns the error flags value
t_byte	__map_check(t_map *s_map)
{
	t_pos_vector	it;
	char			**map;

	it.x = 0;
	map = s_map->map_ptr;
	if (__check_walls(s_map))
		return (s_map->error[1] = 1, 1);
	while (it.x < s_map->row)
	{
		it.y = 0;
		while (it.y < s_map->col && map[(int)it.x][(int)it.y])
		{
			if (map[(int)it.x][(int)it.y] != '0')
				__map_handler(map[(int)it.x][(int)it.y], s_map, \
					(t_pos_vector){it.x, it.y, 0, 0});
			it.y++;
		}
		it.x++;
	}
	__check_components(s_map);
	it.x = 0;
	while (it.x < 7)
		if (s_map->error[(int)it.x++])
			return (1);
	return (0);
}

int	__map_ber_check(char *filepath)
{
	size_t	size;

	size = ft_strlen(filepath);
	if (size < 4)
		return (0);
	return (!ft_strncmp(&filepath[size - 4], ".ber", 4));
}

int	__check_size(t_map *s_map)
{
	if (s_map->row < 2 || s_map->col < 2)
	{
		ft_printf("Error\nMap has little space man :(\n");
		return (0);
	}
	return (1);
}
