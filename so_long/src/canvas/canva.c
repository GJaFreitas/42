/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:17:47 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 18:28:57 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

t_byte		__draw_pixel(int x, int y, int color);
t_sprite	*__load_img(char *texture_name);
void		__draw_img(t_sprite *img, int x_offset, int y_offset);
void		__scale_img(t_sprite *img, t_pos_vector vec);
void		__clear_screen(void);

void	__destroy_canva(void)
{
	mlx_destroy_image(engine()->mlx, canva()->data.img);
}

t_canva	*canva(void)
{
	static t_canva	canva;

	return (&canva);
}

void	start_screen(void)
{
	void		*norminette_dumb;
	t_sprite	*normi_hate;

	norminette_dumb = engine()->mlx;
	normi_hate = &canva()->data;
	canva()->scale_factor = 1;
	canva()->data.width = engine()->width;
	canva()->data.height = engine()->height;
	normi_hate->img = mlx_new_image(norminette_dumb, WIDTH_W, HEIGHT_W);
	normi_hate->address = mlx_get_data_addr(\
					normi_hate->img, \
					&normi_hate->bpp, \
					&normi_hate->line_length, \
					&normi_hate->endian);
	canva()->load_img = __load_img;
	canva()->draw_pixel = __draw_pixel;
	canva()->draw_img = __draw_img;
	canva()->scale_img = __scale_img;
	canva()->clear_screen = __clear_screen;
	canva()->destroy = __destroy_canva;
}
