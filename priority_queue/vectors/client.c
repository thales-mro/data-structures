#include <stdio.h>
#include "priority_queue.h"

int main() {
    int n, i, aux;
    Item item;
    pq_ptr pq = NULL;

    printf("Please insert the size of the Priority Queue: ");
    scanf("%d", &n);
    pq = createPQ(n);

    printf("Please insert %d elements to the Priority Queue: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &aux);
        item.key = aux;
        insertPQ(pq, item);
    }

    printf("Extracting maximum: ");
    item = extractMaximumPQ(pq);
    printf("%d\n", item.key);

    printf("Extracting 2nd maximum: ");
    item = extractMaximumPQ(pq);
    printf("%d\n", item.key);

    return 0;
}