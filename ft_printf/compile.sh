mv main.c main
make re
make clean
mv main main.c
cc main.c libftprintf.a -g -o program
make fclean
clear
./program
