#include <stdio.h>
#include <stdlib.h>

typedef char Titem;
typedef struct node *Tpointer;

typedef struct node {
    Titem item;
    Tpointer next;
} Tnode;

typedef Tpointer Tlist;

void initialize_list(Tlist *list);
void insert_to_list_end (Tlist *list, Titem data);
void delete_first(Tlist *list);  
void print_list (Tlist *list);

int main (void) 
{
	Tlist list;
	initialize_list(&list);
	insert_to_list_end(&list, 'a');
	insert_to_list_end(&list, 'b');
	insert_to_list_end(&list, 'c');
	insert_to_list_end(&list, 'd');
	print_list(&list);
	delete_first(&list);
	print_list(&list);		
	delete_first(&list);
	print_list(&list);		
	delete_first(&list);
	print_list(&list);		          
	delete_first(&list);
	print_list(&list);	        //tulostuu tyhjä lista
	insert_to_list_end(&list, 'e');
	print_list(&list);		

	#if defined(WIN32)||defined(_WIN32)
	system("pause");
	return 0;
	#else
	return 0;
	#endif
}

void initialize_list(Tlist *list)
{
	*list=NULL;
}

void insert_to_list_end(Tlist *list, Titem data)
{
	Tpointer newnode, last;

    newnode = malloc(sizeof(Tnode));
    newnode->item = data;
	newnode->next=NULL;
    if (*list == NULL)
        *list = newnode;       //first node
    else
	{
        last=*list;  //not first node
		while(last->next!=NULL)
			last=last->next;
		last->next=newnode;
	}
}

void delete_first(Tlist *list)
{
	if(*list!=NULL)
	{
		Tpointer aux1, aux2;
		aux1=*list;
		aux2=aux1->next;
		free(aux1);
		printf("\nDeleted\n");
		*list=aux2;
	}
}

void print_list(Tlist *list)
{
    Tpointer what ;
    printf("List :");
    what = *list;//->first;
        while (what != NULL) {
	    printf("%c ", what->item);
	    what = what->next;
    }
	puts("");
}