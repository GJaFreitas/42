#include "../headers/header.h"

int	game_loop(void)
{
	if (game()->to_render)
		game()->render(canva());
	mlx_put_image_to_window(engine()->mlx, engine()->win,
			 canva()->data.img, 0, 0);
	return(0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	start_engine("Gaming", WIDTH, HEIGHT);
	start_game();
	//mlx_loop_hook(engine()->mlx, game_loop, NULL);
	mlx_loop(engine()->mlx);
	return (0);
}

// the hooks, no matter where they are called seem to be giving problems
