# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2025/01/22 17:11:03 by bag              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Compiler -------------------- #

CC = cc

# --- Compiler Flags -------------- #

CFLAGS = -g -Wall -Wextra -Werror

# --- NAME ---------------------- #

NAME = push_swap.out

NODIR = --no-print-directory

# --- DEPENDENCIES ---------------- #

LIBFT = libft/libft.a

SRCS = parsing.c \
       moves.c \
       execution.c \
       show.c \
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

OBJS = $(SRCS:.c=.o)

RM = rm -f

.c.o:
	@$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

$(NAME) : $(LIBFT) $(OBJS)
	@echo Making
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

all: $(NAME)

$(LIBFT):
	@make -C libft $(NODIR)

clean:
	@$(RM) $(OBJS)

fclean:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

re:
	@make fclean $(NODIR)
	@make $(NODIR)

test:
	@make re $(NODIR)
	./$(NAME) 3 2 1

.PHONY: all clean fclean re
