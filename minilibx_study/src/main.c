#include "../includes/lib.h"

int	handle_input(int keycode, t_data data)
{
	if (keycode == XK_Escape)
	{
		mlx_destructor(data);
		exit(0);
	}

	render(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void) argv;
	(void) argc;
	data = data_init();
	if (data == NULL)
		return (ft_printf("Error\n"), 1);
	//mlx_hook(data->mlx_window, 2, KPRESS_M, handle_input, data);
	mlx_key_hook(data->mlx_window, handle_input, data);
	mlx_loop(data->mlx_ptr);
	ft_printf("No problems\n");
	return ((int)mlx_destructor(data));
}
