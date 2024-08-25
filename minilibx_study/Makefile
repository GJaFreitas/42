# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2024/08/25 20:03:59 by gjacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Compiler -------------------- #

CC = cc

# --- Compiler Flags -------------- #

CFLAGS = -g -Wall -Wextra -Werror -O2
LFLAGS = -lXext -lX11 -lm -lz

# --- NAME ---------------------- #

NAME = fun.out

# --- DIRECTORIES ------------------- #

MLXDIR = ./libs/minilibx-linux
LIBFTDIR = ./libs/libft
OBJS_DIR = ./objs
SRCS_DIR = ./src

# --- DEPENDENCIES ---------------- #

SRCS =	$(wildcard src/*.c)
OBJS =	$(SRCS:%.c=%.o)

MLX = libs/minilibx-linux/libmlx.a
LIBFT = libs/libft/libft.a

# -------------------------------- #

RM = rm -f

AR = ar rc

RANLIB = ranlib

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(LFLAGS)
	@echo $(NAME) finished making

$(MLX):
	@make -C libs/minilibx-linux --no-print-directory
	@echo $(MLX) compiled

$(LIBFT):
	@make -C libs/libft --no-print-directory
	@echo $(LIBFT) compiled

all: $(NAME) $(MLX) $(LIBFT)

clean:
	@echo "cleaning"
	@$(RM) $(OBJS)

fclean:
	@echo "deepcleaning"
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

re:
	@make fclean
	@make

run: all
	valgrind ./$(NAME)

.PHONY: all clean fclean re
