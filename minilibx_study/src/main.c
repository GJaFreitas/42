#include "../includes/lib.h"

int	handle_input(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		data_destructor(data);
	if (keycode != XK_Escape)
		data->s->walk(data->s, keycode);
	if (keycode == XK_j)
		data->s->shoot(data->s);

	return (0);
}

int	main(int argc, char **argv)
{
	static t_data	data;
	static o_square	square;

	data.s = &square;
	data_init(&data);
	if (argc == 2)
		data.map = load_map(argv[1]);
	constructor(&square, data.canvas);
	start_screen(&data);
	square.start(&square);
	mlx_key_hook(data.mlx_window, handle_input, &data);
	mlx_loop(data.mlx_ptr);
	ft_printf("No problems\n");
	data_destructor(&data);
	return (0);
}
