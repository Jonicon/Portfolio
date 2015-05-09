#include "intstack.h"
#include <stdio.h>

void initialize_int_stack ( Tintstack *Pstack)  {
     Pstack->top = -1;
}
Tboolean push_int( Tintstack *Pstack, int item) {
     if (Pstack->top >= MAX_INT_STACK_SIZE - 1)
	    return(NOT_OK);
     else {
	    (Pstack->top)++;
	    Pstack->array[Pstack->top] = item;
	    return (OK);
     }
}
Tboolean pop_int( Tintstack *Pstack, int *Pitem) {
     if (Pstack->top == - 1)
	    return(NOT_OK);
     else {
	    *Pitem = Pstack->array[Pstack->top];
	    (Pstack->top)--;
	    return (OK);
     }
}
int is_empty_int_stack(const Tintstack *Pstack ) {
    return  (Pstack->top == -1);
}
void print_int_stack (const Tintstack *Pstack) {
	int i;
	printf("\nStack is ");
	for (i = Pstack->top; i >= 0 ; i-- )
	     printf("\n %d ", Pstack->array[i]);
	printf("\n\n");
}