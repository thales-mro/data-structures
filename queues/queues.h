typedef struct node {
    int data;
    struct node *next;
} node;

typedef node * node_ptr;

typedef struct {
    node_ptr beginning, end;
} Queue;

typedef Queue * queue_ptr;

queue_ptr createQueue();

void freeQueue(queue_ptr queue);

void printQueue();

void queue(queue_ptr q, int element);

int dequeue(queue_ptr q);