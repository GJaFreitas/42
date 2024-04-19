/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:10:37 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/19 19:19:34 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#define BUFFER_SIZE 50

# include <stdlib.h>
# include <unistd.h>

typedef struct _FILES *FILES;
struct _FILES
{
	int	n_files;
	int	*fds;
	int	*location; // Not sure if this is the best name
} ;

char	*get_next_line(int fd);
void	*ft_realloc(void *origin, unsigned int originsize);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int	ft_get_buff_size(char *s);

# endif
