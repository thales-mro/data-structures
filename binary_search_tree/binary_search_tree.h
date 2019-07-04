typedef struct node {
    int data;
    struct node *left, *right, *father;
}node;

typedef node * bst;

bst createBST();

void destroyBST(bst root);

bst insertToBST(bst root, int elem);

bst removeFromBST(bst root, int elem);

bst searchBST(bst root, int elem);

bst minimumBST(bst root);

bst maximumBST(bst root);

bst successorBST(bst n);

bst predecessorBST(bst n);

bst searchBST(bst root, int elem);

void printOrdered(bst root);