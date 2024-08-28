# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2024/04/17 18:27:01 by gjacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Compiler -------------------- #

CC = cc

# --- Compiler Flags -------------- #

CFLAGS = -g -Wall -Wextra -Werror

# --- NAME ---------------------- #

NAME = libft.a

# --- DEPENDENCIES ---------------- #

SRCS = $(wildcard srcs/*/*.c)
SRCS += $(wildcard ft_printf/*.c)
SRCS += $(wildcard get_next_line/*.c)
OBJS = $(SRCS:.c=.o)

DEPS = libft.h

HEAD = includes

RM = rm -f

AR = ar rc

RANLIB = ranlib

.c.o:
	@$(CC) -c $(CFLAGS) $< -o $(<:.c=.o) -I $(HEAD)

$(NAME) : $(OBJS)
	@echo "making in libft :)"
	@$(AR) $(NAME) $(OBJS)
	@$(RANLIB) $(NAME)

all: $(NAME)

clean:
	@echo "cleaning in libft"
	@$(RM) */*/*.o
	@$(RM) */*.o

fclean:
	@echo "deepcleaning in libft"
	@$(RM) */*/*.o
	@$(RM) */*.o
	@$(RM) $(NAME)

re:
	@make fclean
	@make

.PHONY: all clean fclean
