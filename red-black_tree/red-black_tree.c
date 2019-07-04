#include <stdio.h>
#include <stdlib.h>
#include "red-black_tree.h"

int isRed(rbt n) {
    if (n == NULL)
        return 0;
    return n->color == RED;
}

int isBlack(rbt n) {
    if (n == NULL)
        return 1;
    return n->color == BLACK;
}

rbt rotateLeft(rbt root) {
    rbt aux = root->right;
    root->right = aux->left;
    aux->left = root;
    aux->color = root->color;
    root->color = RED;
    return aux;
}

rbt rotateRight(rbt root) {
    rbt aux = root->left;
    root->left = aux->right;
    aux->right = root;
    aux->color = root->color;
    root->color = RED;
    return aux;
}

void climbRed(rbt root) {
    root->color = RED;
    root->left->color = BLACK;
    root->right->color = BLACK;
}

rbt insertRecursive(rbt root, int elem) {
    rbt newNode;

    if (root == NULL) {
        newNode = malloc(sizeof(node));
        newNode->data = elem;
        newNode->right = NULL;
        newNode->left = NULL;
        newNode->color = RED;
        return newNode;
    }

    if (root->data < elem)
        root->right = insertRecursive(root->right, elem);
    else
        root->left = insertRecursive(root->left, elem);

    if (isRed(root->right) && isBlack(root->left))
        root = rotateLeft(root);
    if (isRed(root->left) && isRed(root->left->left))
        root = rotateRight(root);
    if (isRed(root->left) && isRed(root->right))
        climbRed(root);
    
    return root;
}

rbt insertRBT(rbt root, int elem) {
    root = insertRecursive(root, elem);
    root->color = BLACK;
    return root;
}

void printRBTOrdered(rbt root) {
    if (root != NULL) {
        printRBTOrdered(root->left);
        printf("%d ", root->data);
        printRBTOrdered(root->right);
    }
}

void destroyRBT(rbt root) {
    if (root != NULL) {
        destroyRBT(root->left);
        destroyRBT(root->right);
        free(root);
    }
}