#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashing.h"

node_ptr insertList(node_ptr l, char *key, int data) {
    node_ptr newNode;
    
    newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("There are not enough memory!");
        exit(1);
    }

    strcpy(newNode->key, key);
    newNode->data = data;
    newNode->next = l;
    return newNode;
}

node_ptr removeFromList(node_ptr l, char *key) {
    node_ptr ptr, last;

    if (l != NULL) {
        if (strcmp(l->key, key) == 0) {
            free(l);
            return NULL;
        }

        last = l;
        ptr = l->next;
        while(ptr != NULL) {
            if (strcmp(ptr->key, key) == 0) {
                last->next = ptr->next;
                free(ptr);
                break;
            }
        }
    }

    return l;
}

int hash(char *key) {
    int i, n;

    n = 0;
    for (i = 0; i < strlen(key); i++) {
        n = (256 * n + key[i]) % MAX;
    }
    return n;
}

void insert(hash_ptr t, char *key, int data) {
    int n;

    n = hash(key);
    t->vector[n] = insertList(t->vector[n], key, data);
}

void removeNode(hash_ptr t, char *key) {
    int n;

    n = hash(key);
    t->vector[n] = removeFromList(t->vector[n], key);
}