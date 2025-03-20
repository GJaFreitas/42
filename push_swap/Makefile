# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2025/03/20 17:49:15 by gjacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Compiler -------------------- #

CC = cc

# --- Compiler Flags -------------- #

CFLAGS = -g -Wall -Wextra -Werror

# --- NAME ---------------------- #

NAME = push_swap
CHECKER = check

NODIR = --no-print-directory

# --- DEPENDENCIES ---------------- #

LIBFT = libft/libft.a

# --- PUSH SWAP SOURCES ------------ #
VPATH = srcs:operations:stack
SRCS = \
	number_mapping.c \
	check_args.c \
	sort_big.c \
	utils.c \
	sort_small.c \
	chunk_sort_three.c \
	chunk_splits.c \
	chunk_utils.c \
	move_to.c \
	post_sort_optimization.c \
	post_sort_utils.c \
	push_swap.c \

# Push swap operations
SRCS += \
	 operations1.c \
	 operations2.c \
	 operations3.c \

# Stack data structure
SRCS += \
	 stack.c \
	 stack2.c \
	 stack_alloc.c \
	 stack_view.c \

OBJS = $(SRCS:%.c=obj/%.o)

RM = rm -f

all: $(NAME)

$(OBJS):	obj/%.o: %.c
	mkdir -p obj
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME) : $(LIBFT) $(OBJS)
	@echo Making
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) 


$(LIBFT):
	@make -C libft $(NODIR)

clean:
	@$(RM) obj/*

fclean:	clean
	@$(RM) $(NAME)

re:
	@make fclean $(NODIR)
	@make $(NODIR)

test:
	@make re $(NODIR)
	valgrind --leak-check=full ./$(NAME) 1 5 2 4 3 111 27 63 277 89 28 45

.PHONY: all clean fclean re
