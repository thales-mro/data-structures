#include <stdio.h>
#include "red-black_tree.h"

int main() {
    int n, i, aux;
    rbt root = NULL;

    printf("Please enter the number of nodes to be inserted in the reb-black tree: ");
    scanf("%d", &n);

    printf("Please input %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &aux);
        root = insertRBT(root, aux);
    }

    printf("Ordered tree: ");
    printRBTOrdered(root);
    printf("\n");

    destroyRBT(root);
    return 0;
}