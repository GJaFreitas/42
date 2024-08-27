#include "../includes/lib.h"

// Assumes a valid (t_data *) and renders the whole screen
// this will be the only function called to render the screen from now on
int	render(t_data data)
{
	// ...(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)
	// x and y is the place to put the image starting at the uppermost left corner
	// see explanation of 2D screen representation on 1D array in function
	// pixel_put_optimization
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_window,
			 data.canvas.img_ptr, 0, 0);
	return (0);
}

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
			pixel_put_optimization(data.canvas, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
}

