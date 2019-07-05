client: client.o hashing.o
	gcc -g client.o hashing.o -o client

client.o: client.c hashing.h
	gcc -c -ansi -Wall -pedantic-errors -Werror client.c hashing.h

hashing.o: hashing.c hashing.h
	gcc -c -ansi -Wall -pedantic-errors -Werror hashing.c hashing.h