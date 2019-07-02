typedef struct treeNode{
    int data;
    struct treeNode *left, *right;
}treeNode;

typedef treeNode * node_ptr;

node_ptr createBinaryTree(int x, node_ptr left, node_ptr right);

node_ptr searchBinaryTree(node_ptr root, int elem);

int numberNodes(node_ptr root);

int heightBinaryTree(node_ptr root);