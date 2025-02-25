# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2025/02/25 00:05:16 by bag              ###   ########.fr        #
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



###▼▼▼<src-updater-do-not-edit-or-remove>▼▼▼
# **************************************************************************** #
# **   Generated with https://github.com/lorenuars19/makefile-src-updater   ** #
# **************************************************************************** #

SRCS = \
	./srcs/push_swap.c \
	./srcs/number_mapping.c \
	./srcs/sort_big.c \
	./srcs/utils.c \
	./srcs/sort_small.c \
	./srcs/chunk_sort_three.c \
	./srcs/chunk_splits.c \
	./srcs/chunk_utils.c \
	./srcs/move_to.c \

HEADERS = \
	./includes/push_swap.h\

###▲▲▲<src-updater-do-not-edit-or-remove>▲▲▲

# Push swap operations
SRCS += \
	 ./operations/operations1.c \
	 ./operations/operations2.c \
	 ./operations/operations3.c \

# Stack data structure
SRCS += \
	 ./stack/stack.c \
	 ./stack/stack2.c \
	 ./stack/stack_alloc.c \
	 ./stack/stack_view.c \

# Tests
SRCS += \
	 ./test.c \

HEADERS += \
	./stack/stack.h\

OBJS = $(SRCS:.c=.o)

RM = rm -f

.c.o:
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

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
	valgrind --leak-check=full ./$(NAME) 1 5 2 4 3 111 27

.PHONY: all clean fclean re
