#include "../../headers/header.h"


t_sprite	*__generic_load_sprite(char *path)
{
	t_sprite	*s;

	s = malloc_safe(sizeof(t_sprite));
	s = mlx_xpm_file_to_image(engine()->mlx, path, &s->width, &s->height);
	return (s);
}
