all: client

client: queues_client.o queues.o
	gcc queues_client.o queues.o -lm -o client

queues_client.o: queues_client.c queues.h
	gcc -ansi -Wall -pedantic-errors -Werror -c queues_client.c

queues.o: queues.c queues.h
	gcc -ansi -Wall -pedantic-errors -Werror -c queues.c