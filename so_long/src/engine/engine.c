/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 15:11:50 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

int	__key_press(int key, void *v);
int	__key_release(int key, void *v);
int	__mouse_move(int button, int x, int y);
int	__mouse_release(int key, int x, int y);

static void	__destroy_all(void)
{
	if (engine()->win)
		mlx_destroy_window(engine()->mlx, engine()->win);
	mlx_destroy_display(engine()->mlx);
	free_safe(&engine()->mlx);
}

t_engine	*engine(void)
{
	static t_engine	engine;

	return (&engine);
}

void	start_engine(char *title, char **argv, int argc)
{
	engine()->argv = argv;
	engine()->argc = argc;
	engine()->height = HEIGHT_W;
	engine()->width = WIDTH_W;
	engine()->mlx = mlx_init();
	engine()->win = mlx_new_window(engine()->mlx, WIDTH_W, HEIGHT_W, title);
	engine()->destroy = __destroy_all;
	mlx_hook(engine()->win, ON_KEYDOWN, KPRESS_M, __key_press, engine());
	mlx_hook(engine()->win, ON_KEYUP, KRELEASE_M, __key_release, engine());
	mlx_mouse_hook(engine()->win, __mouse_release, engine());
}
/*
	mlx_hook(engine()->win, ON_KEYMOUSEUP, BRELEASE_M, __mouse_release, NULL);
	*/
