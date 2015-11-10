#ifndef list_h
#define list_h

#include <stdio.h>


typedef struct list *List;

List CreateList();
void *get(List lst, int index);
void add(List lst, void *item);
void deletelist(List lst);

#endif /* list_h */
