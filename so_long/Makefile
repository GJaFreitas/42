# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2025/03/21 12:46:59 by gjacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Compiler -------------------- #

CC = cc

# --- Compiler Flags -------------- #

CFLAGS = -g -Wall -Wextra -Werror
LFLAGS = -lXext -lX11 -lm -lz

# --- NAME ---------------------- #

NAME = so_long.out

# --- DIRECTORIES ------------------- #

MLXDIR = ./libs/minilibx-linux
LIBFTDIR = ./libs/libft
OBJS_DIR = ./objs
SRCS_DIR = ./src

# --- DEPENDENCIES ---------------- #

VPATH = src/*:src/*/*:src/object/*/*
SRCS =	$(wildcard src/*/*.c)
SRCS += $(wildcard src/object/*/*.c)
SRCS += ./src/main.c
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

$(GIT):
	@git pull

all: $(GIT) $(NAME) $(MLX) $(LIBFT)

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

run_debug:
	make re
	valgrind --show-leak-kinds=all --track-origins=yes --leak-check=full ./$(NAME) ./maps/map2.ber

run:
	make re
	./$(NAME) ./maps/map2.ber

.PHONY: all clean fclean re
