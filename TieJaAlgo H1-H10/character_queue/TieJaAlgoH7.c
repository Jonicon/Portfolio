/* An array implementation of Queue.
   This is simple solution where array elements are moved
   fordward in the array in dequeue operation*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef char Titem;
#define BLOCKSIZE 3
#define MAX_SIZE 3
/*The interface of queue  */
typedef enum {NOT_OK, OK } Tboolean;
typedef struct {
	     Titem *array;
	     int number_of_items;
		 int size;
} Tqueue;
void initialize_queue (Tqueue *Pqueue);
Tboolean enqueue( Tqueue *p, Titem item);
Tboolean dequeue( Tqueue *p, Titem *Pitem);
void print_queue(const Tqueue *Pqueue);


/*Application    */

int main(void) {
     Tqueue queue;
     Tboolean succeed;
     char chr;

     initialize_queue(&queue);
     printf("\nEnter a letter to be queued ");
     printf("\nor digit 1 to dequeue a letter");
     printf("\nor Return to quit a program\n");
	 
     while (chr != 10 && chr != 13) {
	  scanf("%c", &chr);
      getchar();
	  if (isalpha(chr)) {
		succeed=enqueue(&queue, chr);
		print_queue(&queue);
		}
	  if (chr == '1') {
		succeed = dequeue(&queue, &chr);
		if  (succeed) {
		    printf("\na letter dequeued %c ", chr);
		    print_queue(&queue);
		    }
		else printf("\nDequeue operation failed\n ");
	  }
     }
	 return 0;
}

/*The implementations of operation functions of the queue  */
void initialize_queue ( Tqueue *Pqueue)  {
	 Pqueue->size=MAX_SIZE;
	 Pqueue->array=malloc(sizeof(Titem)*MAX_SIZE);
     Pqueue->number_of_items = 0;
}
Tboolean enqueue( Tqueue *Pqueue, Titem item) {
	int i=0,new_size=Pqueue->size+BLOCKSIZE;
	
     if (Pqueue->number_of_items >=Pqueue->size)
	 {
		Titem *temp_array=malloc(sizeof(Titem)*new_size);
		while(i<Pqueue->size)
		{
			temp_array[i]=Pqueue->array[i];
			i++;
		}
		
		Pqueue->array=temp_array;
		Pqueue->size=new_size;
		Pqueue->array[Pqueue->number_of_items++] = item;
		
		return (OK);
	}
     else {
	    Pqueue->array[Pqueue->number_of_items++] = item;
	    return (OK);
     }
}
Tboolean dequeue( Tqueue *Pqueue, Titem *Pitem) {
     int i;
	 
     if (Pqueue->number_of_items == 0)
	    return(NOT_OK);
     else {
        *Pitem = Pqueue->array[0];
        for (i = 0 ; i < Pqueue->number_of_items-1 ; i++)
            Pqueue->array[i] = Pqueue->array[i+1];
        Pqueue->number_of_items--;
	    return (OK);
     }
}
void print_queue (const Tqueue *Pqueue) {
	int i;
	printf("\nQueue now: \n\n");
	for (i = 0 ; i <  Pqueue->number_of_items ; i++ ) {
	     printf(" %c ", Pqueue->array[i]);
	}
	printf("\n\n");
}
