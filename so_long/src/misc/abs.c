/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 14:19:46 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

float	f_abs(float val)
{
	if (val < 0)
		return (-val);
	return (val);
}

double	d_abs(double val)
{
	if (val < 0)
		return (-val);
	return (val);
}

int	i_abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}
