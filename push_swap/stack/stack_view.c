/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:28:03 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/20 15:32:51 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_print(const t_stack *s)
{
	int	i;

	i = s->size - 1;
	if (s->size == 0)
		return (ft_printf("Empty.\n"), (void)0);
	ft_printf("[ ");
	while (i >= 0)
	{
		ft_printf("%d", s->a[i] - 1);
		i--;
		if (i >= 0)
			ft_printf(", ");
	}
	ft_printf(" ]");
	ft_printf("\n");
}
