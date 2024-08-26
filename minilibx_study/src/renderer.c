#include "../includes/lib.h"

// Rbg encoding but with extra opacity parameter
int	encode_trgb(byte opacity, byte red, byte green, byte blue)
{
	return (opacity << 24 | red << 16 | green << 8 | blue);
}

// Normal rgb system 0 <= x <= 255 (0, 0, 0) is white
// No opacity option
int	encode_rgb(byte red, byte green, byte blue)
{
	return ( red << 16 | green << 8 | blue);
}

// Bit of code from Oceanos video for optimization
void	pixel_put_optimization(t_img img, int x, int y, int color)
{
	int	offset;

	// The screen is just a big array
	// a 1D array at that, this calculation is how we can use
	// an x and y coordinate system in a 1D space
	offset = (img.line_len * y) + (x * (img.bits_per_pixel / 8));

	// offset + address is going to be the offset in the image
	// at the place that img_pixels_tr points to
	*((unsigned int *)(offset + img.address)) = color;
}

void	color_screen(t_data data, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < LENGHT)
	{
		while (x < WIDTH)
		{
			pixel_put_optimization(*(data->img), x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

