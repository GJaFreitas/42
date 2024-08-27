#include "../includes/lib.h"

int	handle_input(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		data_destructor(data);
	if (keycode != XK_Escape)
		walk(keycode, data);

	return (0);
}

int	main(int argc, char **argv)
{
	static t_data	data;

	data_init(&data);
	if (argc == 2)
		data.map = load_map(argv[1]);
	start_screen(data);
	mlx_key_hook(data.mlx_window, handle_input, &data);
	mlx_loop(data.mlx_ptr);
	ft_printf("No problems\n");
	data_destructor(&data);
	return (0);
}
