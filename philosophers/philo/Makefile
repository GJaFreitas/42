# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2025/05/13 09:20:19 by gjacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Compiler -------------------- #

CC = cc

# --- Compiler Flags -------------- #

CFLAGS = -g -Wall -Wextra -Werror

# --- NAME ---------------------- #

NAME = philo

NODIR = --no-print-directory

# --- DEPENDENCIES ---------------- #

LIBFT = libft/libft.a

# --- PUSH SWAP SOURCES ------------ #
SRCS = \
	philosophers.c \
	utils.c \
	actions.c \
	mem_management.c \

OBJS = $(addprefix obj/,$(SRCS:.c=.o))

RM = rm -f

all: $(NAME)

obj/%.o: %.c | obj
	$(CC) -c $(CFLAGS) $< -o $@

obj:
	mkdir -p obj

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 



clean:
	@rm -rf obj

fclean:	clean
	@$(RM) $(NAME)

re:
	@make fclean $(NODIR)
	@make $(NODIR)

r:
	@make
	@./philo 5 800 200 200

.PHONY: all clean fclean re r
