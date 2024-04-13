/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:25:06 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/13 12:40:47 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	new_lst = ft_lstnew((*f)(lst->content));
	while (lst->next != NULL)
	{
		lst = lst->next;
		ft_lstadd_back(&new_lst, ft_lstnew((*f)(lst->content)));
	}
	return (new_lst);
}
