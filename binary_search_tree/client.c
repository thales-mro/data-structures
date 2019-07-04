#include <stdio.h>
#include "binary_search_tree.h"

int main() {
    int n, i, aux;
    bst root = NULL;

    printf("Please insert the number of elements to be added to the Binary Search Tree: ");
    scanf("%d", &n);

    printf("Please insert %d elements:", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &aux);
        root = insertToBST(root, aux);
    }

    printf("Ordered BST: ");
    printOrdered(root);

    printf("\nPlease insert the element to be removed: ");
    scanf("%d", &aux);
    root = removeFromBST(root, aux);

    printf("Ordered BST: ");
    printOrdered(root);
    printf("\n");

    destroyBST(root);
    return 0;
}