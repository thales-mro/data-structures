#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

bst searchBST(bst root, int elem) {
    if (root == NULL || root->data == elem)
        return root;
    if (elem < root->data)
        return searchBST(root->left, elem);
    return searchBST(root->right, elem);
}

bst insertToBST(bst root, int elem) {
    bst newNode;
    if (root == NULL) {
        newNode = malloc(sizeof(node));
        newNode->right = NULL;
        newNode->left = NULL;
        newNode->data = elem;
        return newNode;
    }

    if (root->data < elem)
        root->right = insertToBST(root->right, elem);
    else
        root->left = insertToBST(root->left, elem);
    
    return root;
}

void destroyBST(bst root) {
    if (root != NULL) {
        destroyBST(root->left);
        destroyBST(root->right);
        free(root);
    }
}

bst minimumBST(bst root) {
    if (root == NULL || root->left == NULL)
        return root;
    return minimumBST(root->left);
}

bst maximumBST(bst root) {
    if (root == NULL || root->right == NULL)
        return root;
    return maximumBST(root->right);
}

bst ancestorToRightBST(bst n) {
    if (n == NULL)
        return NULL;
    if (n->father == NULL || n->father->left == n)
        return n->father;
    return ancestorToRightBST(n->father);
}

bst successorBST(bst n) {
    if (n->right != NULL)
        return minimumBST(n);
    return ancestorToRightBST(n);
}

bst ancestorToLeftBST(bst n) {
    if (n == NULL)
        return NULL;
    if (n->father == NULL || n->father->right == n)
        return n->father;
    return ancestorToLeftBST(n->father);
}

bst predecessorBST(bst n) {
    if (n->left != NULL)
        return maximumBST(n);
    return ancestorToLeftBST(n);
}

void removeSuccessor(bst root) {
    bst t = root->right;
    bst father = root;
    
    while(t->left != NULL) {
        father = t;
        t = t->left;
    }
    if (father->left == t)
        father->left = t->right;
    else
        father->right = t->right;
    root->data = t->data;
}

bst removeFromBST(bst root, int elem) {
    if (root == NULL)
        return NULL;
    if (elem < root->data)
        root->left = removeFromBST(root->left, elem);
    else if (elem > root->data)
        root->right = removeFromBST(root->right, elem);
    else if (root->left == NULL)
        return root->right;
    else if (root->right == NULL)
        return root->left;
    else    
        removeSuccessor(root);
    return root;
}

void printOrdered(bst root) {
    if (root != NULL) {
        printOrdered(root->left);
        printf("%d ", root->data);
        printOrdered(root->right);
    }
}