#include <stdio.h>
#include <stdlib.h>
#include "TieJaAlgoH2.h"

void read_times(Time *time)
{
	unsigned short int m,h;

	printf("Anna tunnit: ");
	scanf("%hu", &h);
	
	while(1)
	{
		printf("Anna minuutit: ");
		scanf("%hu", &m);
		if(m>59)
			puts("Minuuttien tulee olla alle 60!");
		else
			break;
	}

	*time=h*60+m;
}

short int compare_times(Time *time1, Time *time2)
{
	int temp0=(*time1*60);
	int temp1=(*time2*60);
	if(temp0<temp1)
		return -1;
	else if(temp0==temp1)
		return 0;
	else
		return 1;
}

Time time_difference(Time *time1, Time *time2, short order)
{
	Time td;
	if(order==-1)
	{
		td=*time2-*time1;
		return td;
	}
	else if(order==1)
	{
		td=*time1-*time2;
		return td;
	}
	else
	{
		td=0;
		return td;
	}
}

void print_times(Time *time)
{
	printf("%02d:%02d\n", *time/60, *time%60);
}

