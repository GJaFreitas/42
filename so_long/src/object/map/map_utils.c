#include "../../../headers/header.h"

static int	__strjoin_map(char *s1, char *s2)
{
	int		total_len;
	char	*new_str;
	int		ret;

	if (!s2)
		return (0);
	ret = ft_strlen(s2);
	total_len = (ft_strlen((char *)s1) + ret + 1);
	new_str = malloc_safe(total_len);
	ft_strlcpy(new_str, s1, total_len);
	ft_strlcat(new_str, s2, total_len);
	free_safe((void**)&s2);
	free_safe((void**)&s1);
	s1 = new_str;
	return (ret);
}

// rows should be initialized in the main map constructor
void	__load_map(char *filepath, t_map *s_map)
{
	char	*buffer;
	int		fd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fd = open(filepath, O_RDONLY);
	buffer = malloc_safe(sizeof(char *));
	while (__strjoin_map(buffer, get_next_line(fd)))
		s_map->row++;
	s_map->row++;
	while (buffer[s_map->col] != '\n')
		s_map->col++;
	s_map->col++;
	s_map->map_ptr = malloc_safe(sizeof(char *) * s_map->row + 1);
	while (i < s_map->row)
	{
		s_map->map_ptr[i] = malloc_safe(s_map->col);
		while (*buffer != '\n')
			s_map->map_ptr[i][j] = (*buffer)++;
		buffer++;
		i++;
	}
	free_safe((void**)&buffer);
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
	while (map[0][i])
		if (map[0][i] != '1' &&\
			map[s_map->row - 1][i] != '1')
			return (1);
	i = 0;
	while (map[i][0])
		if (map[i][0] != '1' &&\
			map[i][s_map->col - 1] != '1')
			return (1);
	return (0);	
}

// returns the error flags value
byte	__map_check(t_map *s_map)
{
	char		**map;
	t_pos_vector	*enemies;
	int		i;
	int		j;
	
	i = 0;
	enemies = s_map->enemies;
	map = s_map->map_ptr;
	if (__check_walls(s_map))
		return (1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				__load_coords(&s_map->start, j, i, &s_map->error);
			if (map[i][j] == 'E')
				__load_coords(&s_map->exit, j, i, &s_map->error);
			if (map[i][j] == 'B')
				__load_coords(enemies++, j, i, NULL);
			j++;
		}
		i++;
	}
	return (s_map->error);
}