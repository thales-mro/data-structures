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

void updateHeapUpwards(pq_ptr pq, int k) {
    if (k > 0 && pq->v[FATHER(k)].key < pq->v[k].key) {
        switchValues(&(pq->v[FATHER(k)]), &(pq->v[k]));
        updateHeapUpwards(pq, FATHER(k));
    }
}

void insertPQHeap(pq_ptr pq, Item item) {
    pq->v[pq->n] = item;
    pq->n++;
    updateHeapUpwards(pq, pq->n - 1);
}

void updateHeapTopToBottom(pq_ptr pq, int k) {
    int greatestChild;

    if (LEFT_CHILD(k) < pq->n) {
        greatestChild = LEFT_CHILD(k);
        if (RIGHT_CHILD(k) < pq->n && pq->v[LEFT_CHILD(k)].key < pq->v[RIGHT_CHILD(k)].key)
            greatestChild = RIGHT_CHILD(k);
        if (pq->v[k].key < pq->v[greatestChild].key) {
            switchValues(&pq->v[k], &pq->v[greatestChild]);
            updateHeapTopToBottom(pq, greatestChild);
        }
    }
}

Item extractMaximumPQHeap(pq_ptr pq) {
    Item item = pq->v[0];

    switchValues(&(pq->v[0]), &(pq->v[pq->n - 1]));
    pq->n--;
    updateHeapTopToBottom(pq, 0);
    return item;
}

void changePriority(pq_ptr pq, int k, int val) {
    if (pq->v[k].key < val) {
        pq->v[k].key = val;
        updateHeapUpwards(pq, k);
    } else {
        pq->v[k].key = val;
        updateHeapTopToBottom(pq, k);
    }
}