all: client

client: queue_client.o queue.o
	gcc queue_client.o queue.o -o client

queue_client.o: queue_client.c queue.h
	gcc -ansi -Wall -pedantic-errors -Werror -c queue_client.c

queue.o: queue.c queue.h
	gcc -ansi -Wall -pedantic-errors -Werror -c queue.c