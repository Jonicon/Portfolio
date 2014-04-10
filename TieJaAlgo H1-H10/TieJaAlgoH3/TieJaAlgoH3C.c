#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char ao=132;

typedef struct{
	char *name;
	unsigned short age;
}Thlo;

void alusta_hlo(Thlo *hlo, const char *input, int number)
{
	hlo->name=malloc(sizeof(char)*20);
	strcpy(hlo->name, input);
	hlo->age=number;
}

void tulosta_hlo(const Thlo *hlo)
{
	#if defined(WIN32)||defined(_WIN32)
	printf("Nimi: %s\nIk%c: %d\n", hlo->name, ae, hlo->age);
	#else
	printf("Nimi: %s\nIkä: %d\n", hlo->name, hlo->age);
	#endif
}

void muuta_nimi(Thlo *hlo, char *new_name)
{
	strcpy(hlo->name, new_name);
}

void kopioi_hlo(Thlo *hlo1, const Thlo *hlo2)
{
	unsigned short i;
	
	for(i=0;i<strlen(hlo2->name);i++)
	{
		hlo1->name[i]=hlo2->name[i];
	}
	
	hlo1->age=hlo2->age;
}

void tuhoa_hlo(Thlo hlo1, Thlo hlo2)
{
	free(hlo1.name);
	free(hlo2.name);
}

int main(void) 
{
	Thlo henkilo, klooni;

	alusta_hlo(&henkilo, "Matti", 20);
	alusta_hlo(&klooni,"", 0);		
	tulosta_hlo(&henkilo);	// tulostetaan henkilo
	tulosta_hlo(&klooni);	// tulostetaan kloonausta varten alustettu klooni

	// kloonataan sijoituksella	       
	kopioi_hlo(&klooni, &henkilo);
	tulosta_hlo(&henkilo);	// tulostetaan henkilo
	tulosta_hlo(&klooni);	// tulostetaan kloonattu klooni
				 
	// kloonattu henkilö tarvitsee oman nimen
	muuta_nimi(&klooni, "Pekka");
	tulosta_hlo(&henkilo);	// tulostetaan henkilo
	tulosta_hlo(&klooni);	// tulostetaan klooni, jonka nimi vaihdettu 
	tuhoa_hlo(henkilo, klooni);
	tulosta_hlo(&henkilo);
	tulosta_hlo(&klooni);
	return 0;
}