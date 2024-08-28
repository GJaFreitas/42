#include "../headers/header.h"

int	game_loop(void)
{

	return(0);
}

int	main(int argc, char **argv)
{
	t_engine	*e;
	//t_game		*g;

	(void)argc;
	(void)argv;
	e = start_engine("Gaming", WIDTH, HEIGHT);
	//g = game();
	mlx_loop_hook(e->mlx, game_loop, NULL);
	mlx_loop(e->mlx);
	return (harbinger_of_chaos(), 0);
}
