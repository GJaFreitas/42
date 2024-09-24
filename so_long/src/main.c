#include "../headers/header.h"

int	game_loop(void)
{
	game()->rm_obj();
	game()->render();
	if (engine()->keys_pressed)
		game()->func_keys();
	if (engine()->mouse_press)
		game()->func_mouse();
	game()->update();
	mlx_put_image_to_window(engine()->mlx, engine()->win,
			 canva()->data.img, 0, 0);
	return(0);
}

int	main(int argc, char **argv)
{
	start_engine("Gaming", argv, argc);
	start_screen();
	start_game();
	//count_overall(WALL);
	mlx_loop_hook(engine()->mlx, game_loop, NULL);
	mlx_loop(engine()->mlx);
	return (0);
}
