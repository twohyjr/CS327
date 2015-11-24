Memory Management in c++

1) forgetting to allocate and then using a  pointer
2) Forgetting to delete a heap object
3) Use an object after its been deleted
4) Invoking delete twice on the same object

An individually allocated piece of data is called a node, cell, or object.

Define root pointers or root references to be all the cells/nodes/objects that
are referenced by a pinter on the stack or global memory.

The pointer reachabilty relation tells if an object on the heap is reachable
from a root pointer or a chain of pointers starting from a root pointer.

we call an object "live" if the pointer reachability relation is true. That is
the object can be reachec by a root refernce or a chain of references from
a root reference.

more formally for a node M and a node N.
M->N if and only if
M holds a reference to N.

The set of live nodes in a hoop is the transitive referetial closure of the
set of root nodes under the -> relation.

Note that the set live is a conservative view of the set of objects that can
be accessed by a program.

----
Why conservative?
What situation would cause some objects not to be available, even though they
are in this live set.

1) local variable after the last use in a method
2) An uninitialized slot in the stack frame
3) An obsolete reference to an object left in a register
----

A nodes "liveness" may be determined directly or indirectly
1) Direct methods require that a record be associated with each node
  in the heap.
  - reference counting
2) Indirect (or tracing) regenerate the set of livenodes whenver a request for
  more memory by the user fails.
  -(garbage collecting)

  Allocation Algorith

  void * allocate(){
    cel * new cell = free_list;
    free_list = free_list->next;
    return newcell;
  }

void * new(){
  if(free_list == null){
    throw out of memory;
  }

  Cell * newcell = allocate;
  newcell -> RC = 1;
  return newcell;
}
