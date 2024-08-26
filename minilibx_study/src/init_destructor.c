#include "../includes/lib.h"

// Do not ever ask why this is necessary,
// if i dont do this then i get 100kb of memory leaks
void	img_destructor(t_img *img, void *mlx_ptr)
{
	mlx_destroy_image(mlx_ptr, img->img_ptr);
}

// Frees and destroys all mlx data and returns 0
int	mlx_destructor(t_data data)
{
	if (data)
	{
		if (data->img)
			img_destructor(data->img, data->mlx_ptr);
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
	}
	return (0);
}

t_img	*img_init()
{
	t_img	*img;

	img = malloc(sizeof(struct s_img));
	if (!img)
		return (NULL);
	img->h = LENGHT;
	img->w = WIDTH;
	return (img);
}

t_data	data_init()
{
	t_data	data;
	data = malloc(sizeof(s_data));
	data->img = img_init();
	if (!data || !(data->img))
		return (mlx_destructor(data), NULL);
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		return (free(data->img), free(data), NULL);
	data->mlx_window = mlx_new_window(data->mlx_ptr,
				WIDTH, LENGHT, "window");
	if (!(data->mlx_window))
		return (mlx_destructor(data), NULL);
	// If it segfaults at this point it would have SIGSEV earlier so no worries 🥰
	data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, LENGHT);
	data->img->address = mlx_get_data_addr(
				data->img->img_ptr, &data->img->bits_per_pixel,
				&data->img->line_len, &data->img->endian);
	return (data);
}
