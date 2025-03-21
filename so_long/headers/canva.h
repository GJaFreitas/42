/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:05:46 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 17:05:47 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVA_H
# define CANVA_H

typedef struct s_canva			t_canva;
typedef struct s_sprite			t_sprite;

# define COLOR_TRANSPARENT 0

typedef struct pos_vector		t_pos_vector;

struct s_sprite
{
	void			*img;
	char			*address;
	int				bpp;
	int				line_length;
	int				endian;
	int				width;
	int				height;
};

struct s_canva
{
	t_sprite		data;
	t_sprite		*(*load_img)(char *texture_name);
	unsigned char	(*draw_pixel)(int x, int y, int color);
	void			(*draw_img)(t_sprite *sprite, int x, int y);
	void			(*scale_img)(t_sprite *sprite, t_pos_vector vec);
	void			(*clear_screen)();
	void			(*destroy)();
	float			scale_factor;
	float			scale_factor_e;
};

t_canva			*canva(void);
void			start_screen(void);
float			scale_to(int w, int h);

#endif
