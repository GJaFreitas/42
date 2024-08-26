#include "../includes/lib.h"

int	handle_input(int keycode, t_game game)
{
	if (keycode == XK_Escape)
	{
		exit(game_end(game, 0));
	}

	render(game->mlx_data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game = game_init(argc, argv);
	//mlx_hook(data->mlx_window, 2, KPRESS_M, handle_input, data);
	mlx_key_hook(game->mlx_data->mlx_window, handle_input, game->mlx_data);
	mlx_loop(game->mlx_data->mlx_ptr);
	ft_printf("No problems\n");
	return (game_end(game, 0));
}
