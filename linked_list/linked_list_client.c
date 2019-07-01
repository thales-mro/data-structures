#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() {
    int n, i, aux;
    node_ptr list, secondList, ptr;

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

    printf("The remaining list is about to be copied:\nCopied list: ");
    secondList = copyList(list);
    printList(secondList);
    printf("Original List: ");
    printList(list);

    printf("Copied List is about to be inverted: \n");
    secondList = invertList(secondList);
    printf("Inverted List: ");
    printList(secondList);

    printf("Contatenating original and inverted lists:\n");
    concatLists(list, secondList);
    printList(list);

    freeList(list);
    freeList(secondList);


    return 0;
}