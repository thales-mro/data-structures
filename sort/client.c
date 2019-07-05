#include <stdio.h>
#include "sort.h"

int main() {
    int *v, *original;
    int n, i, aux;

    printf("Please insert the size of the vector: ");
    scanf("%d", &n);

    original = allocVector(n);
    v = allocVector(n);
    printf("Please insert %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &aux);
        original[i] = aux;
    }

    copy(original, v, n);
    printf("Original array: ");
    printVector(v, n);

    printf("Sorting the array: \n");
    printf("With bubbleSort: ");
    bubbleSort(v, n);
    printVector(v, n);

    printf("Reset manipulated vector to original: ");
    copy(original, v, n);
    printVector(v, n);

    printf("With Insertion Sort: ");
    insertionSort(v, n);
    printVector(v, n);

    printf("Reset manipulated vector to original: ");
    copy(original, v, n);
    printVector(v, n);

    printf("With Selection Sort: ");
    selectionSort(v, n);
    printVector(v, n);

    freeVector(v);
    return 0;
}