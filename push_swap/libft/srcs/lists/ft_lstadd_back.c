/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:37:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/02/18 20:26:37 by bag              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstadd_back(t_list **head, t_list *node)
{
	t_list	*temp;

	if (!head || !node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	temp = ft_lstlast(*head);
	temp->next = node;
	node->prev = temp;
}
