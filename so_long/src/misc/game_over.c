#include "../../headers/header.h"

// TODO: GAME OVER SCREEN
// vector(game()->to_render)->rm_rf
void	game_over(void)
{
	game()->destructor();
	start_game();
}
