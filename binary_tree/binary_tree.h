typedef struct treeNode{
    int data;
    struct treeNode *left, *right;
}treeNode;

typedef treeNode * node_ptr;

node_ptr createBinaryTree(int x, node_ptr left, node_ptr right);

node_ptr searchBinaryTree(node_ptr root, int elem);

int numberNodes(node_ptr root);

int heightBinaryTree(node_ptr root);

void preOrder(node_ptr root);

void postOrder(node_ptr root);

void inOrder(node_ptr root);

int numberLeaves(node_ptr root);

void freeBinaryTree(node_ptr root);