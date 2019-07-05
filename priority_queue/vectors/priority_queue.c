#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

void switchValues(Item *a, Item *b) {
    Item aux = *a;
    *a = *b;
    *b = aux;
}

pq_ptr createPQ(int size) {
    pq_ptr pq;
    
    pq = malloc(sizeof(PQ));
    if (pq == NULL) {
        printf("There are not enough memory!\n");
        exit(1);
    }
    pq->v = malloc(size*sizeof(Item));
    if (pq->v == NULL) {
        printf("There are not enough memory!\n");
        exit(1);
    }
    pq->size = size;
    pq->n = 0;

    return pq;
}

void insertPQ(pq_ptr pq, Item item) {
    pq->v[pq->n] = item;
    pq->n++;
}

Item extractMaximumPQ(pq_ptr pq) {
    int i, max;

    max = 0;
    for(i = 1; i < pq->n; i++)
        if (pq->v[i].key > pq->v[max].key)
            max = i;

    switchValues(&(pq->v[max]), &(pq->v[pq->n - 1]));
    pq->n--;

    return pq->v[pq->n];
}

void destroyPQ(pq_ptr pq) {
    free(pq);
}