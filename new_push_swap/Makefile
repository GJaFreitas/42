# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2025/03/19 15:34:31 by gjacome-         ###   ########.fr        #
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
	./srcs/instructions.c \
	./srcs/instructions2.c \
	./srcs/instructions3.c \
	./srcs/instructions4.c \
	./srcs/main.c \
	./srcs/radix.c \
	./srcs/simple.c \

SRCS += \
	 ./utils/check_args.c \
	 ./utils/index.c \
	 ./utils/t_list.c \
	 ./utils/t_list2.c \
	 ./utils/utils.c \

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
	valgrind --leak-check=full ./$(NAME) 1 5 2 4 3 111 27 63 277 89 28 45

.PHONY: all clean fclean re
