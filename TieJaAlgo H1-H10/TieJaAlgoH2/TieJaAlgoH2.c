#include <stdio.h>
#include <stdlib.h>
#include "TieJaAlgoH2.h"

int main(void)
{
	Time t0, t1, t2;
	short int comp;

	read_times(&t0);
	read_times(&t1);

	comp=compare_times(&t0, &t1);
	t2=time_difference(&t0, &t1, comp);
	
	if(comp==-1)
	{
		printf("Alku: ");	print_times(&t0);
		printf("Loppu: ");	print_times(&t1);
		printf("Erotus: "); print_times(&t2);
	}
	else if(comp==0)
		puts("Ei aikaeroa!");
	else
	{
		printf("Alku: ");	print_times(&t1);
		printf("Loppu: ");	print_times(&t0);
		printf("Erotus: "); print_times(&t2);
	}
	#if defined(WIN32)||defined(_WIN32)
	system("pause");
	return 0;
	#else
	return 0;
	#endif
}