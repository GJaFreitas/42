#include "../../../headers/header.h"

void	__destroy_map(t_map *s_map)
{
	(void)s_map;
}

void	__map_realloc(char **map, int rows)
{
	char	**new;

	(void)map;
	(void)rows;
	new = malloc_safe(sizeof(char *) * (rows + 1));
}

// rows should be initialized in the main map constructor
char	**__load_map(char *filepath, int *rows)
{
	char	**map;
	char	*buffer;
	int		fd;

	fd = open(filepath, O_RDONLY);
	map = malloc_safe(sizeof(char *));
	buffer = get_next_line(fd);
	while (buffer)
	{
		map[*rows] = buffer;
		(*rows)++;
		__map_realloc(map, *rows);
		buffer = get_next_line(fd);
	}
	return (map);
}
