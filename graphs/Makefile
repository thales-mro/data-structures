client: client.o graph.o
	gcc -g client.o graph.o -o client

client.o: client.c graph.h
	gcc -c -g -ansi -Wall -pedantic-errors -Werror client.c graph.h

graph.o: graph.c graph.h
	gcc -c -g -ansi -Wall -pedantic-errors -Werror graph.c graph.h