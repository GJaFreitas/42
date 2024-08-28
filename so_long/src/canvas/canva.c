#include "../../headers/header.h"

t_sprite	*__load_img(char *texture_name);

t_canva	*canva(void)
{
	static t_canva	canva;

	return (&canva);
}

void	start_screen(void)
{
	canva()->data.width = engine()->width;
	canva()->data.height = engine()->height;
	canva()->data.img = mlx_new_image(engine()->mlx, WIDTH, HEIGHT);
	canva()->data.address = mlx_get_data_addr(canva()->data.img,
				&canva()->data.bpp,
				&canva()->data.line_length,
				&canva()->data.endian);
	canva()->load_img = __load_img;
}
