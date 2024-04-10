rm a.out
cd .. && make aclean && make && cd tests
cc *.c ../libft.a
cd .. && make aclean && cd tests
clear
./a.out
