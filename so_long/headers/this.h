/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:56:44 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 16:56:46 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THIS_H
# define THIS_H

// The goal of this is that i can set an array or object as "this"
// and then call it like i do the engine eg: engine()->mlx

typedef struct s_vector		t_vector;
typedef struct s_object		t_object;

typedef struct s_this		t_this;

struct s_this
{
	t_vector		*vector;
	t_object		*object;
};

t_this	*fthis(void);

#endif
