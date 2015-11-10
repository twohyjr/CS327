#include "ll.h"
#include "list.h"
#include <stdlib.h>

struct node
{
    NODEPTR prev;
    NODEPTR next;
    void *data;
};

struct list{
    NODEPTR head;
    NODEPTR tail;
    int numItems;
};



void push(NODEPTR *head, void *data)
{
    NODEPTR n = (NODEPTR)malloc(sizeof(struct node));
    n->data = data;
    if(*head == NULL) *head = n;
    else
    {
        n->next = *head;
       *head = n;
    }
}

void add(LIST lst, void *item){
    
    NODEPTR n = (NODEPTR)malloc(sizeof(struct node));
    n-> next = NULL;
    n->prev=lst->tail;
    n->data = item;
    if(lst->head == NULL){
        lst -> head = n;
        lst -> tail = n;
    }else{
        lst->tail->next = n;
        lst->tail = n;
    }
    lst -> numItems +=1;
}

void deletelist(LIST lst){
    NODEPTR n = lst->head;
    NODEPTR savenext;
    //DO NOTTTT DO THIS
//    while (n) {
//        free(n);
//        n = n->next;
//    }
    
    while (n) {
        savenext = n->next;
        free(n);
        n=savenext;
    }
    free(lst);
}
//THE TEST

//Makefiles
//C coding
//75 min test
//memorize
//Understand Memory Diagrams
