#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void switchValues(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void printVector(int *v, int n) {
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int * allocVector(int n) {
    int *vector;

    vector = malloc(n*(sizeof(int)));
    if (vector == NULL) {
        printf("There are not enough memory!");
        exit(1);
    }

    return vector;
}

void freeVector(int *v) {
    free(v);
}

void copy(int *original, int *cp, int n) {
    int i;

    for (i = 0; i < n; i++)
        cp[i] = original[i];
}

void bubbleSort(int *v, int n) {
    int i, j, switched;

    switched = 1;
    for (i = 0; i < n - 1 && switched; i++) {
        for (j = n - 1; j > i; j--) {
            switched = 0;
            if (v[j - 1] > v[j]) {
                switchValues(&v[j - 1], &v[j]);
                switched = 1;
            }
        }
    }
}

void insertionSort(int *v, int n) {
    int i, j, aux;

    for(i = 0; i < n; i++) {
        aux = v[i];
        for (j = i; j > 0 && aux < v[j - 1]; j--) {
            v[j] = v[j - 1];
        }
        v[j] = aux;
    }
}

void selectionSort(int *v, int n) {
    int i, j, min;

    for(i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min])
                min = j;
        }
        switchValues(&v[i], &v[min]);
    }
}

void updateHeapTopToBottom(int *heap, int n, int k) {
    int greatestChild;
    if (LEFT_CHILD(k) < n) {
        greatestChild = LEFT_CHILD(k);
        if (RIGHT_CHILD(k) < n && heap[LEFT_CHILD(k)] < heap[RIGHT_CHILD(k)])
            greatestChild = RIGHT_CHILD(k);
        if (heap[k] < heap[greatestChild]) {
            switchValues(&heap[k], &heap[greatestChild]);
            updateHeapTopToBottom(heap, n, greatestChild);
        }
    }
}

void heapSort(int *v, int n) {
    int k;

    for (k = n/2; k >= 0; k--)
        updateHeapTopToBottom(v, n, k);
    while(n > 1) {
        switchValues(&v[0], &v[n - 1]);
        n--;
        updateHeapTopToBottom(v, n, 0);
    }
}