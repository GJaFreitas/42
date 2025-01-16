# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2025/01/16 16:28:49 by bag              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Compiler -------------------- #

CC = cc

# --- Compiler Flags -------------- #

CFLAGS = -g -Wall -Wextra -Werror

# --- NAME ---------------------- #

NAME = push_swap.out

# --- DEPENDENCIES ---------------- #

LIBFT = libft/libft.a

SRCS = parsing.c \
       execution.c \
       algo.c \
       dlinked_list/list2.c \
       dlinked_list/list.c \
       push_swap.c \
       list_op.c \
       operations/operations3.c \
       operations/operations1.c \
       operations/operations2.c \
       stack/stack2.c \
       stack/stack.c \

RM = rm -f

$(NAME) : $(LIBFT)
	@echo Making
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

all: $(NAME)

$(LIBFT):
	@make -C libft

clean:
	@echo "cleaning in libft"
	@$(RM) $(OBJS)

fclean:
	@echo "deepcleaning in libft"
	@make clean
	@$(RM) $(NAME)

re:
	@make fclean
	@make

.PHONY: all clean fclean re
