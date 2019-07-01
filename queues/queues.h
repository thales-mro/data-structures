typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    node beginning, end;
} Queue;

typedef Queue * queue_ptr;

queue_ptr createQueue();

void printQueue();