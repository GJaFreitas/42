/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:16:42 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/22 11:20:41 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	mlx_put_image_to_window(engine()->mlx, engine()->win, \
				canva()->data.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	srand(time(NULL));
	start_engine("Gaming", argv, argc);
	start_screen();
	start_game();
	mlx_hook(engine()->mlx, DESTROYNOTIFY, \
		STRUCT_NOTI_MASK, close_game, NULL);
	mlx_loop_hook(engine()->mlx, game_loop, NULL);
	mlx_loop(engine()->mlx);
	return (0);
}
