#include "../includes/lib.h"

// Basically these 2 functions call all other destructors and
// constructors without me needing to bother with what
// pointer goes where

// game_end as the name indicates ends the game lol
int	game_end(t_game game, int ret_value)
{
	mlx_destructor(game->mlx_data);
	free(game->map->map);
	free(game);
	return (ret_value);
}

// game_init if it wasnt clear starts the game 🫶
t_game	game_init(int argc, char **argv)
{
	t_game	game;

	game = malloc(sizeof(s_game));
	game->mlx_data = data_init();
	if (game->mlx_data == NULL)
		return (ft_printf("Error\n"), NULL);
	if (argc == 2)
	{
		game->map = load_map(argv[1]);
		if (!(game->map))
		{
			ft_printf("Error loading map");
			return (NULL);
		}
	}
	return (game);
}
