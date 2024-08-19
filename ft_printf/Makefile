# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2024/08/19 15:23:08 by gjacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = $(wildcard libft/srcs/*/*.c)
SRCS += $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

HEAD = includes

RM = rm -f

AR = ar rc

RANLIB = ranlib

.c.o:
	@$(CC) -c $(CFLAGS) $< -o $(<:.c=.o) -I $(HEAD)

$(NAME) : $(OBJS)	
	@$(AR) $(NAME) $(OBJS)
	@$(RANLIB) $(NAME)

all: $(NAME)

clean:
	cd libft && make clean
	$(RM) *.o

fclean:
	cd libft && make fclean
	make clean
	$(RM) $(NAME)

re:
	make fclean
	make

.PHONY: all clean fclean
