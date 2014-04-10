﻿#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned short int hours;
	unsigned short int minutes;
}*Times;

void read_times(Times t);
short int compare_times(const Times t0, const Times t1);
void time_difference(const Times t0, const Times t1, Times t2, short int order);
void print_times(Times t);
Times create_stack(void);
void destroy_stack(Times t);

int main(void)
{
	Times t0, t1, t2;
	short int comp;

	t0=create_stack();
	t1=create_stack();
	t2=create_stack();
	
	read_times(t0);
	read_times(t1);

	comp=compare_times(t0, t1);
	time_difference(t0, t1, t2, comp);
	
	if(comp==-1)
	{
		printf("Alku: ");	print_times(t0);
		printf("Loppu: ");	print_times(t1);
		printf("Erotus: "); print_times(t2);
	}
	else if(comp==0)
		puts("Ei aikaeroa!");
	else
	{
		printf("Alku: ");	print_times(t1);
		printf("Loppu: ");	print_times(t0);
		printf("Erotus: "); print_times(t2);
	}
	
	destroy_stack(t0);
	destroy_stack(t1);
	destroy_stack(t2);
	
	#if defined(WIN32)||defined(_WIN32)
	system("pause");
	return 0;
	#else
	return 0;
	#endif
}

void read_times(Times t)
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

	t->minutes=m;
	t->hours=h;
}

short int compare_times(const Times t0,const Times t1)
{
	if(t0->hours-t1->hours<0)
		return -1;
	else if(t0->hours-t1->hours>0)
		return 1;
	else
	{
		if(t0->minutes-t1->minutes<0)
			return -1;
		else if(t0->minutes-t1->minutes>0)
			return 1;
		else
			return 0;
	}
}

void time_difference(const Times t0, const Times t1, Times t2, short order)
{
	unsigned short int difference_in_minutes, difference_in_hours, m0, h0, m1, h1;

	m0=t0->minutes;	//Sijoitetaan structissa oleva tieto
	m1=t1->minutes;	//muuttujiin, jottei alkuperäinen data
	
	h0=t0->hours;	//muutu->
	h1=t1->hours;

	if(order==-1)	//jos t1 tiedetään suuremmaksi
	{
		if(m1-m0<0)	//Mutta minuutit ovat sattumoisin pienemmät
		{
			m1+=60;	//Lainataan tunti minuutteina
			h1-=1;	//ja poistetaan yksi tunti
			difference_in_minutes=m1-m0;	//Lasketaan ero minuuteissa
		}
		else
			difference_in_minutes=m1-m0;	//Muutoin lasketaan suoraan
		
		difference_in_hours=h1-h0;	//Lopulta tuntien erotus
	}
	else if(order==0)
	{
		difference_in_hours=0;
		difference_in_minutes=0;
	}
	else
	{
		if(m0-m1<0)	//ks-> ylemmät kommentit
		{
			m0+=60;
			h0-=1;
			difference_in_minutes=m0-m1;
		}
		else
			difference_in_minutes=m0-m1;

		difference_in_hours=h0-h1;
	}
	t2->hours=difference_in_hours;
	t2->minutes=difference_in_minutes;

}

void print_times(Times t)
{
	printf("%02hu:%02hu\n", t->hours, t->minutes);
}

Times create_stack(void)
{
	Times time_stack;
	time_stack=malloc(sizeof(*time_stack));
	return time_stack;
}

void destroy_stack(Times t)
{
	free(t);
}