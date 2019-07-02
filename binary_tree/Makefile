client: client.o binary_tree.o
	gcc -g client.o binary_tree.o -o client

client.o: client.c binary_tree.h
	gcc -c -ansi -Wall -Werror -pedantic-errors -g client.c

binary_tree.o: binary_tree.c binary_tree.h
	gcc -c -ansi -Wall -Werror -pedantic-errors -g binary_tree.c