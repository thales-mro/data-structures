#include <stdio.h>
#include <stdlib.h>
#include "queues.h"

queue_ptr createQueue() {
    queue_ptr newQueue;

    newQueue = malloc(sizeof(Queue));
    if (newQueue == NULL) {
        printf("The are not enough memory!");
        exit(1);
    }

    newQueue->beginning = NULL;
    newQueue->end = NULL;

    return newQueue;
}

void freeList(node_ptr list) {
    if(list != NULL) {
        freeList(list->next);
        free(list);
    }
}

void freeQueue(queue_ptr queue) {
    if (queue->beginning != NULL) {
        freeList(queue->beginning);
    }
    free(queue);
}

void queue(queue_ptr queue, int element) {
    node_ptr ptr;

    ptr = malloc(sizeof(node));
    if (ptr == NULL) {
        printf("The are not enough memory!");
        exit(1);
    }

    ptr->data = element;
    ptr->next = NULL;

    if (queue->beginning == NULL) {
        queue->beginning = ptr;
    } else {
        queue->end->next = ptr;
    }
    queue->end = ptr;
}

int dequeue(queue_ptr queue) {
    int element;
    node_ptr ptr = queue->beginning;
    
    if (ptr == NULL) {
        printf("Queue is empty!");
        exit(1);
    }

    element = ptr->data;
    queue->beginning = queue->beginning->next;
    if (queue->beginning == NULL)
        queue->end = NULL;

    free(ptr);
    return element;
}

void printQueue(queue_ptr queue) {
    node_ptr ptr = queue->beginning;

    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}