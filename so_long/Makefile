# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2025/04/26 11:04:20 by gjacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Compiler -------------------- #

CC = cc

# --- Compiler Flags -------------- #

CFLAGS = -g -Wall -Wextra -Werror -O2
LFLAGS = -lXext -lX11 -lm -lz

# --- NAME ---------------------- #

NAME = so_long

# --- DIRECTORIES ------------------- #

MLXDIR = ./libs/minilibx-linux
LIBFTDIR = ./libs/libft
OBJS_DIR = ./objs
###▼▼▼<src-updater-do-not-edit-or-remove>▼▼▼
# **************************************************************************** #
# **   Generated with https://github.com/lorenuars19/makefile-src-updater   ** #
# **************************************************************************** #

SRCS = \
	./src/game/game.c \
	./src/game/game_utils2.c \
	./src/game/game_utils.c \
	./src/misc/vec_normalization.c \
	./src/misc/abs.c \
	./src/misc/memory.c \
	./src/misc/collision.c \
	./src/misc/rand.c \
	./src/misc/this.c \
	./src/misc/debug.c \
	./src/misc/game_over.c \
	./src/misc/transition.c \
	./src/misc/destroyer_of_all.c \
	./src/engine/key_events.c \
	./src/engine/engine.c \
	./src/engine/mouse_events.c \
	./src/vector/vector_utils.c \
	./src/vector/vector_sort.c \
	./src/vector/vector.c \
	./src/vector/vector_utils3.c \
	./src/vector/vector_utils2.c \
	./src/canvas/canva_utils.c \
	./src/canvas/scale_coords.c \
	./src/canvas/canva_utils2.c \
	./src/canvas/canva.c \
	./src/main.c \
	./src/object/hud/hud.c \
	./src/object/bg/background.c \
	./src/object/counter/counter.c \
	./src/object/generic_functions.c \
	./src/object/map/error.c \
	./src/object/map/map_utils.c \
	./src/object/map/floodfill_remake.c \
	./src/object/map/map_utils2.c \
	./src/object/map/map.c \
	./src/object/player/mouse2.c \
	./src/object/player/player.c \
	./src/object/start/start.c \
	./src/object/collectible/collectible.c \
	./src/object/exit/exit.c \
	./src/object/object_utils.c \
	./src/object/enemy/enemy_utils.c \
	./src/object/enemy/enemy.c \
	./src/object/enemy/enemy_utils2.c \
	./src/object/wall/wall.c \
	./src/object/menu/menu.c \
	./src/object/fireball/fireball.c \

###▲▲▲<src-updater-do-not-edit-or-remove>▲▲▲

# --- DEPENDENCIES ---------------- #

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
