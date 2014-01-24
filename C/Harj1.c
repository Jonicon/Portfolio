/********************************
Joni Kontusalmi, Harkat osa 1:
*********************************/




// App begins
#include <stdio.h>

// prototypes
void swap(int *a, int *b);
void threeSort(int *a, int *b, int *c);
void mirrorArray(int *arr, int size);
int getMax(int *arr, int size);
void sortArrayInt(int *arr, int n);


// App begins
int main (void)
{
	int arr[3];
	
	
	// 1.
	int a=10, b=100, c=1;
	printf("%d %d %d", &a, &b, &c);
	sortInts(*a, *b, *c);
	printf("%d %d %d", &a, &b, &c);
	
	//2.
	
}

/***************************************************
	Definistions Begin
****************************************************/
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/* 
1. Kirjoita funktio, joka vaihtaa (”muuttuja-”) parametrina saamiensa kolmen kokonaisluvun arvot 
niin, että ensimmäisenä parametrina olevaan muuttujaan tulee arvoista pienin, toiseen 
keskimmäinen ja kolmanteen arvoista suurin 
*/
void threeSort(int *a, int *b, int *c)
{
	if (*a > *b) swap(a, b); 
	if (*a > *c) swap(a, c);
	if (*b > *c) swap(b, c);
}


/* 2. Kirjoita funktio, joka vaihtaa parametrina saamansa kokonaislukutaulukon luvut päinvastaiseen 
järjestykseen. Toisena parametrina välitetään taulukon alkioiden lukumäärä. 
 */
void mirrorArray(int *arr, int size)
{
	int i, j;
	for (i=0; i<size; ++i)
	{
		for (j=size-1, i > 0; --i)
		{
			swap(arr[i], arr[j]);
		}
	}
}


 
 /* 3. Kirjoita funktio, joka palauttaa parametrina saamansa kokonaislukutaulukon alkioista suurimman. 
Toisena parametrina välitetään taulukon alkioiden lukumäärä. 
 */
 int getMax(int *arr, int size)
 {
	int i, max = 0;
	for (i=0; i < size; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
 }
 
 /*  
4. EKSTRATEHTÄVÄ NOPEILLE: Kirjoita funktio, joka lajittelee parametrina saamansa 
kokonaislukutaulukon 
*/
void sortArrayInt(int *arr, int size)
 {
	int i, j;
	for (i = 0; i < size-1; i++) 
	{
		for (j = i+1; j < size; j++)
		{
			if (arr[i] > arr[j]) swap(arr[i], arr[j]);
		}
	}
 }