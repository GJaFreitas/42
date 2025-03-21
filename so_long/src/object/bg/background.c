/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 15:13:11 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/header.h"

t_object	*new_bg(void)
{
	t_object	*bg;

	bg = constructor(sizeof(t_object));
	bg->type = BG;
	bg->pos.w = WIDTH_W;
	bg->pos.h = HEIGHT_W;
	bg->sprite = canva()->load_img("textures/background(new).xpm");
	return (bg);
}
