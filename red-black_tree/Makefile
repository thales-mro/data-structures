client: client.o red-black_tree.o
	gcc -g client.o	red-black_tree.o -o client

client.o: client.c red-black_tree.c
	gcc -c -ansi -Wall -pedantic-errors -Werror client.c red-black_tree.c

red-black_tree.o: red-black_tree.c red-black_tree.h
	gcc -c -ansi -Wall -pedantic-errors -Werror red-black_tree.c red-black_tree.h