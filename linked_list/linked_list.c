#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

node_ptr createList() {
    return NULL;
}

void freeList(node_ptr list) {
    if(list != NULL) {
        freeList(list->next);
        free(list);
    }
}

void printList(node_ptr list) {
    node_ptr ptr;

    for (ptr = list; ptr != NULL; ptr = ptr->next) {
        printf("%d ", ptr->data);
    }
    printf("\n");
}

node_ptr addElement(node_ptr list, int element) {
    node_ptr newPtr;

    newPtr = malloc(sizeof(node));
    if (newPtr == NULL) {
        printf("There are not enough memory!");
        freeList(list);
        exit(1);
    }

    newPtr->data = element;
    newPtr->next = list;
    return newPtr;
}

node_ptr find(node_ptr list, int elem) {

    while(list != NULL) {
        if (list->data == elem)
            return list;
        list = list->next;
    }

    return NULL;
}

node_ptr removeFromList(node_ptr list, int elem, int removeAll) {
    node_ptr ptr, last;

    ptr = list->next;
    if (list->data == elem) {
        free(list);
        if (!removeAll)
            return ptr;
        list = ptr;
    }

    last = list;

    while(ptr != NULL) {
        if (ptr->data == elem) {
            last->next = ptr->next;
            free(ptr);
            ptr = last->next;
            if (!removeAll)
                break;
        } else {
            last = ptr;
            ptr = ptr->next;

        }
    }

    return list;
}

node_ptr removeFirst(node_ptr list, int elem) {
    return removeFromList(list, elem, 0);
}

node_ptr removeAll(node_ptr list, int elem) {
    return removeFromList(list, elem, 1);
}

node_ptr copyList(node_ptr list) {
    node_ptr newList, prev;

    prev = newList;
    while(list != NULL) {
        node_ptr aux = malloc(sizeof(node));
        aux->data = list->data;
        aux->next = NULL;
        prev->next = aux;
        prev = prev->next;
        list = list->next;
    }


    return newList;
}