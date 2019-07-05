client: client.o sort.o
	gcc -g client.o sort.o -o client

client.o: client.c sort.h
	gcc -c -ansi -Wall -pedantic-errors -Werror client.c sort.h

sort.o: sort.c sort.h
	gcc -c -ansi -Wall -pedantic-errors -Werror sort.c sort.h
	