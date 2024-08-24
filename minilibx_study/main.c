#include "lib.h"
#include "libs/minilibx-linux/mlx.h"
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

// Frees and destroys all mlx data and returns 0
int	mlx_destructor(t_data data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	return (0);
}

// Error returns a 1
// If no errors occur then returns 0
t_data	data_init()
{
	t_data	data;
	data = malloc(sizeof(s_data));
	if (!data)
		return (NULL);
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		return (mlx_destroy_display(data->mlx_ptr),
		free(data), NULL);
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
	{
	}
	if (keycode == XK_g)
	{
	}
	if (keycode == XK_b)
	{
	}
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

	if (data->mlx_window)
		printf("a\n");
	mlx_hook(data->mlx_window, 2, KPRESS_M, handle_input, data);
	mlx_loop(data->mlx_ptr);

	return (mlx_destructor(data));
}
