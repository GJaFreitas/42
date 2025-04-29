# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2025/04/30 00:38:19 by gjacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Compiler -------------------- #

CC = cc

# --- Compiler Flags -------------- #

CFLAGS = -g -Wall -Wextra -Werror

# --- NAME ---------------------- #

NAME = shell

NODIR = --no-print-directory

# --- DEPENDENCIES ---------------- #

LIBFT = libft/libft.a

# --- PUSH SWAP SOURCES ------------ #
VPATH = src:src/functions
SRCS = \
       minishell.c \
       tokenize.c \
       exec.c \
       builtin.c \
       ft_echo.c

OBJS = $(addprefix obj/,$(SRCS:.c=.o))

RM = rm -f

all: $(NAME)

obj/%.o: %.c | obj
	$(CC) -c $(CFLAGS) $< -o $@

obj:
	mkdir -p obj

$(NAME) : $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) 


$(LIBFT):
	@make -C libft $(NODIR)

clean:
	@rm -rf obj

fclean:	clean
	@$(RM) $(NAME)

re:
	@make fclean $(NODIR)
	@make $(NODIR)

r:
	make
	@./$(NAME)

.PHONY: all clean fclean re r
