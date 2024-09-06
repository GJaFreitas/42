#include "../headers/header.h"

int	game_loop(void)
{
	game()->render();
	game()->func_keys();
	game()->func_mouse();
	game()->rm_obj();
	mlx_put_image_to_window(engine()->mlx, engine()->win,
			 canva()->data.img, 0, 0);
	return(0);
}

int	main(int argc, char **argv)
{
	start_engine("Gaming", WIDTH, HEIGHT);
	start_screen();
	start_game();
	if (argc == 2)
		game()->maps[0] = new_map(argv[1]);
	mlx_loop_hook(engine()->mlx, game_loop, NULL);
	mlx_loop(engine()->mlx);
	return (0);
}
