all: client

client: linked_list_client.o linked_list.o
	gcc linked_list_client.o linked_list.o -lm -o client

linked_list_client.o: linked_list_client.c linked_list.h
	gcc -ansi -Wall -pedantic-errors -Werror -c linked_list_client.c

linked_list.o: linked_list.c linked_list.h
	gcc -ansi -Wall -pedantic-errors -Werror -c linked_list.c