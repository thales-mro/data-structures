#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

node_ptr createBinaryTree(int x, node_ptr left, node_ptr right) {
    node_ptr ptr;
    
    ptr = malloc(sizeof(treeNode));
    ptr->data = x;
    ptr->left = left;
    ptr->right = right;
    return ptr;
}

node_ptr searchBinaryTree(node_ptr root, int elem) {
    node_ptr left;
    
    if (root == NULL || root->data == elem)
        return root;

    left = searchBinaryTree(root->left, elem);
    if (left != NULL)
        return left;
    
    return searchBinaryTree(root->right, elem);
}

int numberNodes(node_ptr root) {
    if(root == NULL)
        return 0;

    return numberNodes(root->left) + numberNodes(root->right) + 1;
}

int heightBinaryTree(node_ptr root) {
    int hLeft, hRight;
    
    if (root == NULL)
        return 0;
    
    hLeft = heightBinaryTree(root->left);
    hRight = heightBinaryTree(root->right);
    return 1 + (hLeft > hRight ? hLeft : hRight);
}

void preOrder(node_ptr root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node_ptr root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(node_ptr root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int numberLeaves(node_ptr root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return numberLeaves(root->left) + numberLeaves(root->right);
}

void freeBinaryTree(node_ptr root) {
    if (root != NULL) {
        freeBinaryTree(root->left);
        freeBinaryTree(root->right);
        free(root);
    }
}