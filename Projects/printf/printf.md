# Printf

## Stack and Heap

It is wrong to return a reference to a local variable, because the memory for this variable is deallocated when the function ends. The following example shows the problem :

```c
/* wrong version */
int *table_of(int num, int len)
{
    int table[len+1];
    for (int i=0; i <= len; i++)
    {
        table[i] = i*num;
    }
    return table;
}
/* A cleaner solution would be to let the caller allocate themomory and pass in a pointer to that */
void table_of(int num, int len, int[] table);
```

### Stack

Data on the stack can be used without pointers.

The limitation of stack-allocated memory is that we need to know the size of that table needed beforehand.

### Heap

Data on the stack is allocated automatically when we do a function call, and removed when we return.

Data on the heap must be allocated and de-allocated manually, using malloc and free.

### malloc

The operation to allocate a chunk of memory on the heap is malloc.

### void*

void* is the type of untyped pointers. A void* pointer can be converted into any other pointer type without an explicit cast.

### free

Never free memory that is not dynamically allocated.

```c
/* "hello" is statically allocated */
char    *x = "hello";
free(x);
```

### aliasing

Pointers are called aliases if they both point to same address. Aliasing can make some of the bugs hard to spot.

```c
int     *x = malloc(1000);
int     *y = malloc(1000);
int     *z = x;
y = x;
int     *w = y;
/* double free ! */
free(w);
free(z);
```

## Pointer

What is the basic function of pointer ?

Swap value. In C, variables is passed as a copy into argument when calling functions. The modification we make will not influence the origin. However, pointer stores memory address of a variable. If we change a value at a certain memory address, it will be always there.  

```c
void swap_wrong(int x, int y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void swap_true(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
```

## Linked List

Why do we use pointer to linked list element when declaring it ?

1. Because we use pointer to get reference of the next node. A pointer to a node will simplify the linking step. The more important is that, manipulating the pointer to a variable declared locally is not decent.

2. By allocating memory for node in heap, the lists will remain as long as we wish. If we allocates it in stack by the traditional way like that for int, the lists will be destroyed when function ends. What's more, the space in stack in much less than that in heap.

```c
#include <stdlib.h>
typedef struct               s_linked_list
{
    int                     data;
    struct s_linked_list    *next;
}                           t_linked_list;

int main(void)
{
    t_linked_list           *head = NULL;
    t_linked_list           *second = NULL;
    t_linked_list           *end = NULL;

    head = (t_linked_list *)malloc(sizeof(t_linked_list));
    second = (t_linked_list *)malloc(sizeof(t_linked_list));
    end = (t_linked_list *)malloc(sizeof(t_linked_list));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    end->data = 3;
    third->next = NULL;
}

```
