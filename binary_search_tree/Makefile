client: client.o binary_search_tree.o
	gcc -g client.o binary_search_tree.o -o client

client.o: client.c binary_search_tree.h
	gcc -c -ansi -Wall -pedantic-errors -Werror client.c binary_search_tree.h

binary_search_tree.o: binary_search_tree.c binary_search_tree.h
	gcc -c -ansi -Wall -pedantic-errors -Werror binary_search_tree.c binary_search_tree.h