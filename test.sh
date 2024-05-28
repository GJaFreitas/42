#! /bin/sh

# Script to silence make since it always annoys me with a ton of text
# Also cleaning the object files immediatly bc i dont like seeing them in vim file explorer

cd ft_printf && make re >/dev/null || make
make clean
cd ..
cc -g printftester.c ft_printf/libftprintf.a
./a.out
