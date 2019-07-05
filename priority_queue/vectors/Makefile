client: client.o priority_queue.o
	gcc -g priority_queue.o client.o -o client

client.o: client.c priority_queue.h
	gcc -c -ansi -Wall -pedantic-errors -Werror client.c priority_queue.h

priority_queue.o: priority_queue.c priority_queue.h
	gcc -c -ansi -Wall -pedantic-errors -Werror priority_queue.c priority_queue.h
