#include "../../../headers/header.h"

void	__map_realloc(char **map, int rows);
void	__load_map(int fd, t_map *s_map);
void	__load_coords(t_pos_vector *pos, int x, int y, byte *error);
byte	__map_check(t_map *s_map);

static t_sprite	*__get_sprite(int flag)
{
	if (flag)
		return (((t_map*)fthis()->object)->enemy_sprite);
	return (((t_map*)fthis()->object)->collectible_sprite);
}

static void	__render_map(void)
{
	int	i;

	i = 0;
	while (((t_map*)fthis()->object)->enemies[i].x\
		|| ((t_map*)fthis()->object)->collectibles[i].x)
	{
		if (((t_map*)fthis()->object)->enemies[i].x)
			canva()->scale_img(__get_sprite(1),\
		(t_pos_vector){((t_map*)fthis()->object)->enemies[i].x,\
				((t_map*)fthis()->object)->enemies[i].y,\
				((t_map*)fthis()->object)->pos.w,\
				((t_map*)fthis()->object)->pos.h});
		if (((t_map*)fthis()->object)->collectibles[i].x)
			canva()->scale_img(__get_sprite(0),\
		(t_pos_vector){((t_map*)fthis()->object)->collectibles[i].x,\
				((t_map*)fthis()->object)->collectibles[i].y,\
				((t_map*)fthis()->object)->pos.w,\
				((t_map*)fthis()->object)->pos.h});
		i++;
	}
}

static void	__destroy_map(void)
{
	t_map	*s_map;
	int		i;

	i = 0;
	s_map = (t_map*)fthis()->object;
	while (i < s_map->row)
		free_safe((void**)&s_map->map_ptr[i++]);
	free_safe((void**)&s_map->map_ptr);
	mlx_destroy_image(engine()->mlx, s_map->sprite->img);
	mlx_destroy_image(engine()->mlx, s_map->enemy_sprite->img);
	mlx_destroy_image(engine()->mlx, s_map->collectible_sprite->img);
	free(s_map->get_sprite());
	free(__get_sprite(1));
	free(__get_sprite(0));
}

t_map	*new_map(char *filepath)
{
	t_map	*map;

	map = constructor(sizeof(t_map));
	map->type = MAP;
	__load_map(open(filepath, O_RDONLY), map);
	map->render = __render_map;
	map->destructor = __destroy_map;
	map->collectible_sprite = canva()->load_img("textures/steel.xpm");
	map->enemy_sprite = canva()->load_img("textures/slime.xpm");
	map->sprite = canva()->load_img("textures/slime.xpm");
	map->pos.w = 100;
	map->pos.h = 100;
	if (__map_check(map))
		map->destructor();
	return (map);
}
