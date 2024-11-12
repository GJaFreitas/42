CC = cc

CFLAGS = -g -Wall -Wextra -Werror

LIBFT = libft/libft.a

SERVER = server

CLIENT = client

default: all

$(SERVER): $(LIBFT) server.c
	$(CC) $(CFLAGS) server.c $(LIBFT) -o server
	@echo "Server compiled"

$(CLIENT): $(LIBFT) client.c
	$(CC) $(CFLAGS) client.c $(LIBFT) -o client
	@echo "Client compiled"

$(LIBFT):
	@make -C libft/ --no-print-directory
	@echo "LIBFT compiled"

all: $(LIBFT) $(CLIENT) $(SERVER)

clean:
	@echo "No objects lol"

fclean:
	@rm server
	@rm client
re:
	@make fclean
	@make

.PHONY: all clean fclean re
