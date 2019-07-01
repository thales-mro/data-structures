#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() {
    int n, i, aux;
    node_ptr list, ptr;

    list = createList();

    printf("Please insert the number of elements to be added to the linked list: ");
    scanf("%d", &n);

    printf("Please insert %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &aux);
        list = addElement(list, aux);
    }
    printList(list);

    printf("Please insert element to be found: ");
    scanf("%d", &aux);
    ptr = find(list, aux);

    if(ptr != NULL)
        printf("Element %d found\n", ptr->data);
    printList(list);

    printf("Please insert element to be removed (once): ");
    scanf("%d", &aux);
    list = removeFirst(list, aux);
    printList(list);

    printf("Please insert element to be removed (all occurences): ");
    scanf("%d", &aux);
    list = removeAll(list, aux);
    printList(list);

    freeList(list);
    return 0;
}