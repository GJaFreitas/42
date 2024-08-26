#include "../includes/lib.h"

unsigned char	*get_map(int fd, int *linecount)
{
	byte	*map;
	byte	*buf;
	
	// TODO:
	// Weird notation here but im not going to dedicate to much time
	// trying to figure out how to best write this condition
	// if only norminette let me assing inside the condition
	buf = (byte*)1;
	*linecount = 0;
	while (buf)
	{
		if (buf > (byte*)1)
			free(buf);
		buf = (byte*)get_next_line(fd);
		map = (byte*)ft_strjoin((char*)map, (char*)buf);
		linecount++;
	}
	return (map);
}

t_map	load_map(char *file_path)
{
	t_map	map;
	int	fd;

	map = malloc(sizeof(s_map));
	fd = open(file_path, O_RDONLY);
	map->fd = fd;
	map->map = get_map(fd, &(map->row));
	map->col = ft_strlen_gnl((char*)(map->map), 1);
	return (map);
}
