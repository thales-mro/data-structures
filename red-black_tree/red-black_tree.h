enum Color {RED, BLACK};

typedef struct node {
    int data;
    enum Color color;
    struct node *left, *right;
} node ;

typedef node * rbt;

rbt insertRBT(rbt root, int elem);

void printRBTOrdered(rbt root);

void destroyRBT(rbt root);