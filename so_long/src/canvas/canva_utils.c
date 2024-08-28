#include "../../headers/header.h"

t_sprite	*__load_img(char *texture_name)
{
	t_sprite	*new_sprite;

	new_sprite = malloc_safe(sizeof(t_sprite));
	new_sprite->img = mlx_xpm_file_to_image(engine()->mlx,
				texture_name,
				&new_sprite->width,
				&new_sprite->height);
	new_sprite->address = mlx_get_data_addr(new_sprite->img,
				&new_sprite->bpp,
				&new_sprite->line_length,
				&new_sprite->endian);
	return (new_sprite);
}
