/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:45:20 by gjacome-          #+#    #+#             */
/*   Updated: 2024/06/21 00:28:27 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include "libft/ft_printf/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct {
	int	*arr;
	int	size;
} Stack;

void	push_swap(char *input);

#endif
