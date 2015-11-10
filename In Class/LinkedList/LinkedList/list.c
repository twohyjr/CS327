#include "list.h"
#include "ll.h"



List CreateList()
{
    List lst = (List)malloc(sizeof(struct list));
    lst -> head = NULL;
    lst -> tail = NULL;
    lst -> numItems = 0;
    return lst;
}

void *get(List lst, int index)
{
    NODEPTR n = lst ->head;
    int i;
    int numitems;
    if((index < 0) || (index >= lst -> numItems))
    {
        for (i = 0; i < index; i++) {
            n = n -> next;
        }
    }
    return n -> data;
}
