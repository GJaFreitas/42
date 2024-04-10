# --- Compiler -------------------- #

CC = cc

# --- Compiler Flags -------------- #

CFLAGS = -g -Wall -Wextra -Werror

# --- TARGET ---------------------- #

TARGET = libft.a

# --- DEPENDENCIES ---------------- #

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

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

all: $(TARGET)

clean:
	$(RM) *.o

aclean:
	$(RM) $(TARGET) *.o

.PHONY: all clean
