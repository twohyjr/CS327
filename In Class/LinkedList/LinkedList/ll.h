//LINKED LIST
#ifndef LL_H_
#define LL_H_
#define NULL
#define NULL 0
#include "ll.h"
#endif
typedef struct node *NODEPTR;
typedef struct list *LIST;

void push(NODEPTR *head, void *data);
void add(LIST lst, void *item);