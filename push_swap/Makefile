# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2024/06/20 23:50:43 by gjacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap.a

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

HEAD = includes

RM = rm -f

AR = ar rc

RANLIB = ranlib

.c.o:
	@$(CC) -c $(CFLAGS) $< -o $(<:.c=.o) -I $(HEAD)

$(NAME) : $(OBJS)
	@echo "Making really hard, really making it quite well"
	@make -C libft
	@$(AR) $(NAME) $(OBJS)
	@$(RANLIB) $(NAME)

all: $(NAME)

clean:
	@echo "cleaning"
	@cd libft && make clean
	@$(RM) *.o

fclean:
	@echo "deepcleaning"
	@cd libft && make fclean
	@$(RM) *.o
	@$(RM) $(NAME)

re:
	@make fclean
	@make

.PHONY: all clean fclean libft
