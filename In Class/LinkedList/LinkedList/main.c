#include <stdio.h>
#include "ll.h"

int main(int argc, const char * argv[]) {
    
    NODEPTR head = NULL;
    int *mydata = (int*)malloc(sizeof(int));
    *mydata = 42;
    push(&head,mydata);
    
    return 0;
}
