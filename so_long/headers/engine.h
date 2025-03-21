/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:30:00 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 18:30:01 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "helper_structs.h"

typedef unsigned char		t_byte;

typedef struct s_engine		t_engine;

struct s_engine
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	t_pos_vector	mouse;
	void			(*destroy)(void);
	int				keys_pressed;
	int				mouse_press;
	t_byte			keys[75000];
	int				argc;
	char			**argv;
};

t_engine	*engine(void);
void		start_engine(char *title, char **argv, int argc);

#endif
