#include <stdio.h>
#include "binary_tree.h"

int main() {
    node_ptr root;

    printf("Populating the binary tree for this specific test\n");
    root = createBinaryTree(10, createBinaryTree(1, NULL, NULL), createBinaryTree(100, NULL, NULL));
    
    printf("Number of nodes: %d\n", numberNodes(root));
    printf("Height: %d\n", heightBinaryTree(root));
    printf("preOrder: ");
    preOrder(root);
    printf("\n");
    printf("postOrder: ");
    postOrder(root);
    printf("\n");
    printf("inOrder: ");
    inOrder(root);
    printf("\n");
    printf("Number of leaves: %d\n", numberLeaves(root));

    freeBinaryTree(root);
    return 0;
}