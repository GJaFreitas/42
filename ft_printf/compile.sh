#! /bin/sh

# Script to silence make since it always annoys me with a ton of text
# Also cleaning the object files immediatly bc i dont like seeing them in vim file explorer

make >/dev/null || make
make clean
