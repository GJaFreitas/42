#include "../../headers/header.h"

byte		__draw_pixel(int x, int y, int color);
t_sprite	*__load_img(char *texture_name);
void		__draw_img(t_sprite *img, int x_offset, int y_offset);

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
	canva()->draw_pixel = __draw_pixel;
	canva()->draw_img = __draw_img;
}