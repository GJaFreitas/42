# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2024/04/16 18:54:19 by gjacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Compiler -------------------- #

CC = cc

# --- Compiler Flags -------------- #

CFLAGS = -g -Wall -Wextra -Werror

# --- NAME ---------------------- #

NAME = libft.a

# --- DEPENDENCIES ---------------- #

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
BONUSSRCS = $(wildcard *_bonus.c)
BONUSOBJS = $(BONUSSRCS:.c=.o)

DEPS = libft.h

HEAD = includes

RM = rm -f

AR = ar rc

RANLIB = ranlib

.c.o:
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o) -I $(HEAD)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

all: $(NAME)

bonus: $(NAME)
	make fclean
	make

clean:
	$(RM) *.o

fclean:
	$(RM) $(NAME) *.o

re:
	make fclean
	make

.PHONY: all clean fclean
