clear
cc -g -o program -Wall -Werror -Wextra -D BUFFER_SIZE=$1 get_next_line.c get_next_line_utils.c main.c
