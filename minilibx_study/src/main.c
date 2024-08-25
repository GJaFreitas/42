#include "../includes/lib.h"
/*

typedef struct	s_xvar
{
	Display		*display;
	Window		root;
	int			screen;
	int			depth;
	Visual		*visual;
	Colormap	cmap;
	int			private_cmap;
	t_win_list	*win_list;
	int			(*loop_hook)();
	void		*loop_param;
	int			use_xshm;
	int			pshm_format;
	int			do_flush;
	int			decrgb[6];
	Atom		wm_delete_window;
	Atom		wm_protocols;
	int 		end_loop;
}				t_xvar;

*/

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
		img_destructor(data->img, data->mlx_ptr);
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free(data);
	return (0);
}

// Error returns a 1
// If no errors occur then returns 0

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
	return (data);
}

int	handle_input(int keycode, t_data data)
{
	if (keycode == XK_Escape)
	{
		mlx_destructor(data);
		exit(0);
	}
	if (keycode == XK_r)
		color_screen(data, encode_rgb(255, 0, 0));
	else if (keycode == XK_g)
		color_screen(data, encode_rgb(0, 255, 0));
	else if (keycode == XK_b)
		color_screen(data, encode_rgb(0, 0, 255));
	else if (keycode == XK_s)
		the_walking_square(data);
		//draw_square(50, 50, 100, encode_trgb(190, 150, 150, 0), data);
	// ...(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)
	// x and y is the place to put the image starting at the uppermost left corner
	// see explanation of 2D screen representation on 1D array in file:
	// renderer.c:13
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img->img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void) argv;
	(void) argc;
	data = data_init();
	if (data == NULL)
		return (1);


	data->img->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, LENGHT);

	//char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
	data->img->address = mlx_get_data_addr(data->img->img_ptr, &data->img->bits_per_pixel,
					      &data->img->line_len, &data->img->endian);
	if (!data->img->address)
		return (mlx_destructor(data));

	//mlx_hook(data->mlx_window, 2, KPRESS_M, handle_input, data);
	mlx_key_hook(data->mlx_window, handle_input, data);
	mlx_loop(data->mlx_ptr);

	ft_printf("No problems\n");
	return (mlx_destructor(data));
}
