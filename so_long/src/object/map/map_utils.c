#include "../../../headers/header.h"

static int	__strjoin_map(char *s1, char *s2)
{
	int		ret;

	if (!s2)
		return (0);
	ret = ft_strlen(s2);
	ft_strlcat(s1, s2, ft_strlen(s1) + ret + 1);
	free_safe((void**)&s2);
	return (ret);
}

// Diabolical return() for the sake of lines ahead

// Assume fd is valid since its treated in the new_map function
// if it isn't it will be 0
void	__load_map(int fd, t_map *s_map)
{
	char	buffer[2048];
	int		buf;
	int		i;
	int		j;

	i = 0;
	buf = 0;
	if (!fd)
		return (s_map->map_ptr = NULL, (void)0);
	ft_bzero(buffer, 2048);
	while (__strjoin_map(buffer, get_next_line(fd)))
		s_map->row++;
	while (buffer[s_map->col] != '\n')
		s_map->col++;
	s_map->map_ptr = malloc_safe(sizeof(char *) * s_map->row + 1);
	while (i < s_map->row)
	{
		s_map->map_ptr[i] = malloc_safe(s_map->col + 1);
		j = 0;
		while (buffer[buf] != '\n' && buffer[buf])
			s_map->map_ptr[i][j++] = buffer[buf++];
		s_map->map_ptr[i][j] = 0;
		buf++;
		i++;
	}
	close(fd);
}

void	__load_coords(char c, t_map *s_map, float x, float y)
{
	if (c == 'P' && s_map->start.x)
		return (s_map->error[4] = 1, (void)0);
	if (c == 'E' && s_map->exit.x)
		return (s_map->error[5] = 1, (void)0);
	if (c == 'E')
	{
		s_map->exit.x = x;
		s_map->exit.y = y;
		game()->add_obj(new_exit(x, y));
	}
	else if (c == 'P')
	{
		s_map->start.x = x;
		s_map->start.y = y;
		game()->add_obj(new_start(x, y));
	}
}

// Checks if the outside of the map is walls
byte	__check_walls(t_map *s_map)
{
	char		**map;
	int		i;

	i = 0;
	map = s_map->map_ptr;
	while (i < s_map->col)
		if (map[0][i] != '1' ||\
			map[s_map->row - 1][i] != '1')
			return (1);
		else
			i++;
	i = 0;
	while (i < s_map->row)
		if (map[i][0] != '1' ||\
			map[i][s_map->col - 1] != '1')
			return (1);
		else
			i++;
	return (0);	
}

void	__map_handler(char c, t_map *s_map, t_pos_vector pos)
{
	if (c == 'P')
		__load_coords(c, s_map, pos.y, pos.x);
	else if (c == 'E')
		__load_coords(c, s_map, pos.y, pos.x);
	else if (c == 'B')
		game()->add_obj(new_enemy(pos.y, pos.x));
	else if (c == 'C')
		game()->add_obj(new_collectible(pos.y, pos.x));
	else if (c == '1')
		game()->add_obj(new_wall(pos.y, pos.x));
	else
		s_map->error[0] = c;
}
