/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:16:42 by gjacome-          #+#    #+#             */
/*   Updated: 2025/04/26 11:24:36 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int	__map_ber_check(char *filepath);
int	__fd_check(int fd);

int	game_loop(void)
{
	game()->rm_obj();
	game()->render();
	if (engine()->keys_pressed)
		game()->func_keys();
	game()->update();
	mlx_put_image_to_window(engine()->mlx, engine()->win, \
				canva()->data.img, 0, 0);
	return (0);
}
//mlx_string_put(engine()->mlx, engine()->win, 500, 500, 87215, "HAIIIIII");

int	__initial_checks(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (ft_printf("Error\nInvalid args\n"), 1);
	if (!__map_ber_check(argv[1]))
		return (ft_printf("Error\nNo .ber\n"), 1);
	fd = open(argv[1], O_RDONLY);
	fd = __fd_check(fd);
	if (!fd)
		return (ft_printf("Error\nInvalid fd.\n"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (__initial_checks(argc, argv))
		return (1);
	srand(time(NULL));
	start_engine("Gaming", argv, argc);
	start_screen();
	start_game();
	mlx_loop_hook(engine()->mlx, game_loop, NULL);
	mlx_loop(engine()->mlx);
	return (0);
}
