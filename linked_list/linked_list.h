typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct node * node_ptr;

node_ptr createList();

void freeList(node_ptr list);

void printList(node_ptr list);

node_ptr addElement(node_ptr list, int element);

node_ptr find(node_ptr list, int elem);

node_ptr removeFirst(node_ptr list, int elem);

node_ptr removeAll(node_ptr list, int elem);

node_ptr copyList(node_ptr list);

node_ptr invertList(node_ptr list);