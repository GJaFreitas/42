/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:21:56 by gjacome-          #+#    #+#             */
/*   Updated: 2025/02/18 20:28:53 by bag              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstadd_front(t_list **head, t_list *node)
{
	if (!head || !node)
		return ;
	if (*head != NULL)
	{
		node->next = *head;
		(*head)->prev = node;
	}
	*head = node;
}
