#include "../headers/header.h"

int	game_loop(void)
{
	game()->render();
	if (engine()->keys_pressed)
		game()->func_keys();
	game()->update();
	game()->rm_obj();
	game()->add_queue();
	if (engine()->mouse_press)
		game()->func_mouse();
	mlx_put_image_to_window(engine()->mlx, engine()->win,
			 canva()->data.img, 0, 0);
	return(0);
}

int	main(int argc, char **argv)
{
	start_engine("Gaming", argv, argc);
	start_screen();
	start_game();
	mlx_loop_hook(engine()->mlx, game_loop, NULL);
	mlx_loop(engine()->mlx);
	return (0);
}
