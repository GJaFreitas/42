/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/26 13:49:29 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/header.h"
#include <fcntl.h>
#include <stdio.h>

void	__draw_walls(t_map *s_map);
void	__map_realloc(char **map, int rows);
void	__load_map(int fd, t_map *s_map);
void	__load_coords(t_pos_vector *pos, int x, int y, t_byte *error);
t_byte	__map_check(t_map *s_map);
void	__flood_fill_r(t_map *s_map, int x, int y);
void	__print_error_msg(t_byte *error);
int		__map_ber_check(char *filepath);
int		__check_size(t_map *s_map);

// Pass 'e' for the enemy sprite, 'c' for collectible and nothing for
// the map sprite
static t_sprite	*__get_sprite(char flag)
{
	if (flag == 'e')
		return (((t_map *)fthis()->object)->enemy_sprite);
	if (flag == 'c')
		return (((t_map *)fthis()->object)->collectible_sprite);
	return (((t_map *)fthis()->object)->sprite);
}

static void	__destroy_map(void)
{
	t_map	*s_map;
	int		i;

	i = 0;
	s_map = (t_map *)fthis()->object;
	while (s_map->map_ptr && i < s_map->row)
		free_safe((void **)&s_map->map_ptr[i++]);
	free_safe((void **)&s_map->map_ptr);
	mlx_destroy_image(engine()->mlx, s_map->sprite->img);
	mlx_destroy_image(engine()->mlx, s_map->enemy_sprite->img);
	mlx_destroy_image(engine()->mlx, s_map->collectible_sprite->img);
	free(__get_sprite(0));
	free(__get_sprite('e'));
	free(__get_sprite('c'));
}

int	__fd_check(int fd)
{
	int	check;

	check = read(fd, NULL, 0);
	if (check == -1)
		return (0);
	return (fd);
}

static int	__map_init(t_map *map, char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	__load_map(fd, map);
	close(fd);
	map->error[7] = 1;
	map->error[8] = 1;
	map->render = NULL;
	map->destructor = __destroy_map;
	map->collectible_sprite = canva()->load_img("textures/steel.xpm");
	map->enemy_sprite = canva()->load_img("textures/slime.xpm");
	map->sprite = canva()->load_img("textures/slime.xpm");
	map->get_sprite = __get_sprite;
	canva()->scale_factor = scale_to(map->col, map->row);
	canva()->scale_factor_e = canva()->scale_factor / 2;
	map->pos.h = map->row * canva()->scale_factor;
	map->pos.w = map->col * canva()->scale_factor;
	return (1);
}

t_map	*new_map(char *filepath)
{
	t_map	*map;
	int		errors;

	map = constructor(sizeof(t_map));
	map->type = MAP;
	__map_init(map, filepath);
	if (!__check_size(map))
		return (object((t_object *)map)->destructor(), \
		free(map), harbinger_of_chaos(), NULL);
	errors = __map_check(map);
	__flood_fill_r(map, map->start.x, map->start.y);
	if (errors || map->error[7] || map->error[8])
	{
		__print_error_msg(map->error);
		return (object((t_object *)map)->destructor(), \
		free(map), harbinger_of_chaos(), NULL);
	}
	game()->collectibles_num = map->collectible_num;
	return (map);
}
