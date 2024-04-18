# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2024/04/18 13:22:55 by gjacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c libft/libft.a
OBJS = $(SRCS:.c=.o)

HEAD = includes

RM = rm -f

AR = ar rc

RANLIB = ranlib

.c.o:
	@$(CC) -c $(CFLAGS) $< -o $(<:.c=.o) -I $(HEAD)

$(NAME) : $(OBJS)
	@cd libft && make && make clean
	@$(AR) $(NAME) $(OBJS)	
	@$(RANLIB) $(NAME)

all: $(NAME)

clean:
	$(RM) *.o

fclean:
	cd libft && make fclean
	make clean
	$(RM) $(NAME)

re:
	make fclean
	make

.PHONY: all clean fclean
