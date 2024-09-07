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

void	__load_map(int fd, t_map *s_map)
{
	char	buffer[2048];
	int		buf;
	int		i;
	int		j;

	i = 0;
	buf = 0;
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

void	__load_coords(t_pos_vector *pos, int x, int y, byte *error)
{
	if (error && pos->x && pos->y)
	{
		*error = 1;
		return ;
	}
	pos->x = x;
	pos->y = y;
}

// Checks if the outside of the map is walls
static byte	__check_walls(t_map *s_map)
{
	char		**map;
	int		i;

	i = 0;
	map = s_map->map_ptr;
	while (i < s_map->col)
		if (map[0][i] != '1' &&\
			map[s_map->row - 1][i] != '1')
			return (1);
		else
			i++;
	i = 0;
	while (i < s_map->row)
		if (map[i][0] != '1' &&\
			map[i][s_map->col - 1] != '1')
			return (1);
		else
			i++;
	return (0);	
}

static void	__map_handler(char c, t_map *s_map, t_pos_vector pos)
{
	int	i;

	i = 0;
	if (c == 'P')
		__load_coords(&s_map->start, pos.y, pos.x, &s_map->error);
	else if (c == 'E')
		__load_coords(&s_map->exit, pos.y, pos.x, &s_map->error);
	else if (c == 'B')
	{
		printf("inimigooo x: %.2f, y: %.2f\n", pos.x, pos.y);
		while (s_map->enemies[i++].x)
			;
		__load_coords(&s_map->enemies[i], pos.y, pos.x, NULL);
	}
	else if (c == 'C')
	{
		while (s_map->collectibles[i++].x)
			;
		__load_coords(&s_map->collectibles[i], pos.y, pos.x, NULL);
	}
	else
		s_map->error = 1;
}

// returns the error flags value
byte	__map_check(t_map *s_map)
{
	char		**map;
	int		i;
	int		j;
	
	i = 0;
	map = s_map->map_ptr;
	if (__check_walls(s_map))
		return (1);
	while (i < s_map->row)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0')
				__map_handler(map[i][j], s_map,\
					(t_pos_vector){i, j, 0, 0});
			j++;
		}
		i++;
	}
	return (s_map->error);
}
