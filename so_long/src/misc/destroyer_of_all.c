/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer_of_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/22 11:13:33 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

int	close_game(void *ptr)
{
	(void)ptr;
	harbinger_of_chaos();
	return (0);
}

void	harbinger_of_chaos(void)
{
	game()->goodbye = 1;
	canva()->destroy();
	game()->destructor();
	engine()->destroy();
	exit(0);
}
