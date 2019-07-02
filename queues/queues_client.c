#include <stdio.h>
#include "queues.h"

int main() {
    int n, i, aux;
    queue_ptr q;

    q = createQueue();
    printf("Please insert the number of elements to be added to the queue: ");
    scanf("%d", &n);

    printf("Please insert %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &aux);
        queue(q, aux);
    }

    printf("Queue: ");
    printQueue(q);

    printf("After 2 dequeues: \n");
    printf("Element: %d\n", dequeue(q));
    printf("Element: %d\n", dequeue(q));
    printQueue(q);
    printf("Queueing again:\n");
    queue(q, 100);
    printQueue(q);

    freeQueue(q);
    return 0;
}