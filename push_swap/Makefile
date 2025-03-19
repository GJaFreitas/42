# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2025/03/18 17:27:52 by gjacome-         ###   ########.fr        #
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
SRCS = \
	./srcs/number_mapping.c \
	./srcs/sort_big.c \
	./srcs/utils.c \
	./srcs/sort_small.c \
	./srcs/chunk_sort_three.c \
	./srcs/chunk_splits.c \
	./srcs/chunk_utils.c \
	./srcs/move_to.c \
	./srcs/post_sort_optimization.c \
	./srcs/post_sort_utils.c \
	./srcs/push_swap.c \

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

# --- CHECKER SOURCES ------------ #
CHECKER_SRCS = \
	       ./srcs/number_mapping.c \
	       ./srcs/sort_big.c \
	       ./srcs/utils.c \
	       ./srcs/sort_small.c \
	       ./srcs/chunk_sort_three.c \
	       ./srcs/chunk_splits.c \
	       ./srcs/chunk_utils.c \
	       ./srcs/move_to.c \
	       ./srcs/post_sort_optimization.c \
	       ./srcs/post_sort_utils.c \

# Push swap operations
CHECKER_SRCS += \
		./operations/operations1.c \
		./operations/operations2.c \
		./operations/operations3.c \

# Stack data structure
CHECKER_SRCS += \
		./stack/stack.c \
		./stack/stack2.c \
		./stack/stack_alloc.c \
		./stack/stack_view.c \

CHECKER_SRCS += \
		./checker/checker.c \
		./checker/checker_utils.c \


OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

RM = rm -f

.c.o:
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

$(NAME) : $(LIBFT) $(OBJS)
	@echo Making
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) 

$(CHECKER) : $(CHECKER_OBJS)
	@echo Making checker
	@$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIBFT) -o $(CHECKER) 

all: $(NAME) $(CHECKER)

$(LIBFT):
	@make -C libft $(NODIR)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(CHECKER_OBJS)

fclean:
	@$(RM) $(OBJS)
	@$(RM) $(CHECKER_OBJS)
	@$(RM) $(NAME)
	@$(RM) $(CHECKER)

re:
	@make fclean $(NODIR)
	@make $(NODIR)

test:
	@make re $(NODIR)
	valgrind --leak-check=full ./$(NAME) 1 5 2 4 3 111 27 63 277 89 28 45

.PHONY: all clean fclean re
