#include <stdio.h>
#include <stdlib.h>
#include "TieJaAlgoH2.h"

typedef struct{
	Time t;
	float temperature;
}Tmeas;

const char ae=132; // 'ä'
const char oe=142; // 'ö'

void lue_mittaus(Tmeas *measures)
{
	
	#if defined(WIN32)||defined(_WIN32)
	printf("Anna l%cmp%c: ",ae,oe);
	scanf("%f", &measures->temperature);
	#else
	printf("Anna lämpö: ");
	scanf("%f", &measures->temperature);
	read_times(&measures->t);
	#endif
}

int pienempi(Tmeas *measure0,Tmeas *measure1)
{
	if(measure0->temperature<measure1->temperature)
		return 1;
	else
		return 0;
}

int aikaisempi(Tmeas *measure0,Tmeas *measure1)
{
	if(compare_times(&measure0->t, &measure1->t)==1)
		return 0;
	else
		return 1;
}

void tulosta_mittaus(Tmeas *measures)
{
	#if defined(WIN32)||defined(_WIN32)
	print_times(&measures->t);
	printf("L%cmp%c: %.2f\n",ae,oe,measures->temperature);
	#else
	print_times(&measures->t);
	printf("Lämpö: %.2f\n",ae,oe,measures->temperature);
	#endif
}

int main(void) 
{
    Tmeas m1, m2;
	
    lue_mittaus(&m1);
    lue_mittaus(&m2);
	
    if(pienempi(&m1, &m2))
        printf("\nMittaus 1 oli pienempi\n");
    else
		#if defined(WIN32)||defined(_WIN32)
 	    printf("\nMittaus 2 oli pienempi tai yht%c suuri\n",ae);
		#else
		printf("\nMittaus 2 oli pienempi tai yhtä suuri\n");
		#endif

    if(aikaisempi(&m1, &m2))
        printf("\nMittaus 1 oli aikaisempi\n");
    else
		printf("\nMittaus 2 oli aikaisempi tai samanaikainen\n");
	
	tulosta_mittaus(&m1);
	tulosta_mittaus(&m2);
	
    return 0;
}