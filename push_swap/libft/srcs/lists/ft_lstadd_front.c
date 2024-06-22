/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:21:56 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/19 17:08:59 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstadd_front(t_list **head, t_list *node)
{
	t_list	*temp;

	if (!head || !node)
		return ;
	temp = *head;
	node->next = temp;
	*head = node;
}
