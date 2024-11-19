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

byte	__draw_pixel(int x, int y, unsigned int color)
{
	char		*screen;
	t_sprite	*img;

	if (color == COLOR_TRANSPARENT)
		return (1);
	if (x >= canva()->data.width || y >= canva()->data.height
     		|| x < 0 || y < 0)
		return (0);
	img = &canva()->data;
	screen = img->address + (y * img->line_length) + (x * (img->bpp / 8));
	*(unsigned int *)screen = color;
	return (1);
}

unsigned int	__get_color(t_sprite *img, int x, int y)
{
	char		*screen;
	int		color;

	screen = img->address + (y * img->line_length) + (x * (img->bpp / 8));
	color = *(unsigned int *)screen;
	return (color);
}

void	__draw_img(t_sprite *img, int x_offset, int y_offset)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			__draw_pixel((x + x_offset), (y + y_offset), __get_color(img, x, y));
			x++;
		}
		y++;
	}
}

void	__scale_img(t_sprite *img, t_pos_vector vec)
{
	int 	x;
	int	y;
	t_pos_vector v;
	
	y = 0;
	v.y = 0;
	v.h = (float)img->height / vec.h;
	v.w = (float)img->width / vec.w;
	while (y < vec.h)
	{
		x = 0;
		v.x = 0;
		while (x < vec.w)
		{
			__draw_pixel((x + vec.x), (y + vec.y), __get_color(img, v.x, v.y));
			v.x += v.w;
			x++;
		}
		y++;
		v.y += v.h;
	}
}
