# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:16:20 by gjacome-          #+#    #+#              #
#    Updated: 2024/04/15 18:15:10 by gjacome-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Compiler -------------------- #

CC = cc

# --- Compiler Flags -------------- #

CFLAGS = -g -Wall -Wextra -Werror

# --- TARGET ---------------------- #

TARGET = libft.a

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

$(TARGET) : $(OBJS)
	$(AR) $(TARGET) $(OBJS)
	$(RANLIB) $(TARGET)

bonus: $(BONUSOBJS) $(OBJS)
	$(AR) $(TARGET) $(OBJS)
	$(RANLIB) $(TARGET)

all: $(TARGET)

clean:
	$(RM) *.o

fclean:
	$(RM) $(TARGET) *.o

re:
	make fclean
	make

.PHONY: all clean fclean
