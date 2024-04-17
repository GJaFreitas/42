/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:53:46 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/17 17:48:51 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_recursive_deletion(t_list *lst, void (*del)(void *))
{
	if (lst->next != NULL)
		ft_recursive_deletion(lst->next, (*del));
	ft_lstdelone(lst, (*del));
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	ft_recursive_deletion(*lst, (*del));
	lst = NULL;
}
