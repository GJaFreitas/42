#include "../includes/lib.h"

// Do not ever ask why this is necessary,
// if i dont do this then i get 100kb of memory leaks
static void	img_destructor(t_img *img, void *mlx_ptr)
{
	if (img && img->img_ptr)
		mlx_destroy_image(mlx_ptr, img->img_ptr);
}

// Frees and destroys all mlx data and returns 0
void	data_destructor(t_data *data)
{
	img_destructor(&data->canvas, data->mlx_ptr);
	if (data->mlx_window)
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	data_init(t_data *data)
{
	data->canvas.h = LENGHT;
	data->canvas.w = WIDTH;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->mlx_window = mlx_new_window(data->mlx_ptr,
				WIDTH, LENGHT, "window");
	if (!data->mlx_window)
		return (data_destructor(data));
	// If it segfaults at this point it would have SIGSEV earlier so no worries 🥰
	data->canvas.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, LENGHT);
	if (!data->canvas.img_ptr)
		return (data_destructor(data));
	data->canvas.address = mlx_get_data_addr(
				data->canvas.img_ptr, &data->canvas.bits_per_pixel,
				&data->canvas.line_len, &data->canvas.endian);
}
