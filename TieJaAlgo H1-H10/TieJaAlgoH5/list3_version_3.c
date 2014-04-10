/* Array implementation of an ordered list. The order is defined
   as alphabetic order. The location in the array presents the order.
   This version is independent (on source level) of the item type
   stored in list*/
#include <stdio.h>
#include <stdlib.h>

/*ADT item  */
typedef char Titem;
int read_item(Titem *item);
void print_item(Titem item);
int compare(Titem item1, Titem item2);

/*ADT list */
#define MAX 10
typedef struct  {
	   int count;
	   Titem array[MAX];
} TOrderedList;
void initialize_list(TOrderedList *list);
int insert_item(TOrderedList *list, Titem item);
int retrieve_ith(const TOrderedList *list, int i, Titem *item);
int number_of_items(const TOrderedList *list);
int list_empty(const TOrderedList *list);

int main (void) {
     TOrderedList list; Titem item;
     int i , succeed, no, result;
     initialize_list(&list);
     printf("\n Enter items in any order\n");

     for (i = 0 ; i < 5 ; i++) {
        read_item(&item);
        if (!insert_item(&list, item))
            printf("\nList is full");
     }

     printf("List ouputted using for loop and retrieve_ith function:\n");
     for (i=0; i<number_of_items(&list); i++) {
	   retrieve_ith(&list, i, &item);
	   print_item(item);
     }
     system("pause");
     return 0;
}

/*Operation function implementations for ADT list  */
void initialize_list(TOrderedList *list) {
     list->count = 0;
}
int insert_item(TOrderedList *list, Titem item) {
    int find_position(Titem *array, Titem item, int number_of_items);
    int make_room(Titem *array, int where, int size_of_array);
    int i;
    if (list->count < MAX ) {
	      i = find_position(list->array, item,  list->count);
	      make_room(list->array,i, list->count);
	      list->array[i] = item;
	      list->count++;
	      return 1; }
    else
	return 0;
}
int retrieve_ith(const TOrderedList *list, int i, Titem *item) {
     if (!list_empty(list) && i <list->count) {
	     *item = list->array[i];
	     return 1;
     }
     else return 0;
}

int number_of_items(const TOrderedList *list){
     return list->count;
}
int list_empty(const TOrderedList *list) {
    return !list->count;
}
/*These are "private" low level functions used to implement public
 operation functions for list  */
int find_position(Titem *array, Titem item, int number_of_items) {
	int i=0;
	while (compare(array[i], item) < 0 && i < number_of_items) i++;
	return i;
}
int make_room(Titem *array, int where, int number_of_items) {
	int i;
	if (number_of_items < MAX) {
		for ( i = number_of_items - 1 ; i >= where ; i-- )
		    array[i+1] = array[i];
		return 1; }
	else
		return 0;
}


/*These are operation functions for abstract datatype Titem  */

int read_item(Titem *item) {
      Titem aux;
      fflush(stdin);
      *item = getchar();
      return 1;
}

void print_item(Titem item) {
	   printf("%c\n", item);
}

int compare(Titem item1 , Titem item2) {
    if ((int)item1 < (int)item2)
	return -1;
    else if ((int)item1 == (int)item2)
	return 0;
    else
	return 1;
}
