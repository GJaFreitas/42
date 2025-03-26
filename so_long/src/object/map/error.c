/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/25 17:07:12 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/header.h"

void	__print_error_msg(t_byte *error)
{
	ft_printf("Error\n");
	ft_printf("Invalid map:\n");
	if (error[0])
		ft_printf("Unknown char: %c\n", error[0]);
	if (error[1])
		ft_printf("Invalid wall layout.\n");
	if (error[2])
		ft_printf("No start\n");
	if (error[3])
		ft_printf("No exit\n");
	if (error[4])
		ft_printf("Multiple starts\n");
	if (error[5])
		ft_printf("Multiple exits\n");
	if (error[6])
		ft_printf("No collectibles\n");
	if (error[7])
		ft_printf("No path to end\n");
	ft_printf("\nAborting:\nCalling cleaning crew\n'Free all this up boys!'\n");
}
