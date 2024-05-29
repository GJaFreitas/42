/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:10:37 by gjacome-          #+#    #+#             */
/*   Updated: 2024/05/13 15:39:02 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
    // Whats left after a whole line has been returned from get_next_line
    char    *leftover;
    // Size of the leftover string
    int     size;
} t_data;

char	*get_next_line(int fd);
char    *read_line(t_data *data, int fd);
char	*ft_getline(t_data *data, int count);

#endif
