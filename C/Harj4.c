/********************************
Joni Kontusalmi, Harkat osa 4:
*********************************/




// App begins
#include <stdio.h>

// prototypes
char* encryptCaesar(char* string, int n);

//main begins




/***************************************************
	Definistions Begin
****************************************************/

/**************************************
	Tätä tarvitaan kohta
****************************************/
void lowerToUpper(char* string)
{
	int i;
	for(i=0; i < strlen(string); i++)
	{
		if (string[i] >= 97 && string[i] <= 122)
		{
			string[i] -= 32;
		} 
		else if (string[i] == 132 ) 
			string[i] += 10;
		else if (string[i] == 162 ) 
			string[i] += 5; 
	}
}

/**************************************
	Tätä tarvitaan kohta
****************************************/
int findChar(const char *string, const char c)
{
	int i=0;
	while (string[i] != c)
	{
		i++;
		if (i > strlen(string))
			return 0;
	}
	return i;
}


/*1. Caesarian ecryption 
Kirjoita ohjelma, joka kysyy käyttäjältä kokonaisluvun n ja lukee sen jälkeen puskuriin käyttäjän 
antaman tekstin. Ohjelma salakirjoittaa tekstin ns. Caesar-salakirjoitusta käyttäen
*/
char* encryptCaesar(char* string, int n)
{
	int i, j;
	const char c[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÖÄ";
	lowerToUpper(string);
	n = n % strlen(c) + n;
	
	for(i = 0; i < strlen(string); i++)
	{
		j = findChar(c, string[i]);
		string[i] = c[j];
	}
	return string;
}

/*2. Tee ohjelma, joka laskee tekstitiedostoon tallennetuista henkilöiden tiedoista keskiarvot sekä 
minimit ja maksimit. Tiedot tulostetaan kuvaruudulle. 

*/

void getAveragesFromFile()
{
	char filename[] = "data.txt";
	char fName[20];
	char lName[20];
	int age=0, weight=0, height=0;
	int maxAge=0, maxWeight=0, maxHeight=0;
	int minAge=1000, minWeight=1000, minHeight=1000;
	int sumAge=0, sumWeight=0, sunHeight=0, sumPersons=0;
	double avgAge=0, avgWeight=0, avgHeight=0;
	
	FILE *fhnd = fopen(filename, "r");
	while (!EOF)
	{
		fscanf(fhnd, "%s %s %d %d %d", fName, lName, age, weight, height);
		if (age >= maxAge)
			maxAge = age;
		if (weight >= maxWeight)
			maxWeight = weight;
		if(height >= maxHeight)
			maxHeight = height;
		if(age <= minAge)
			minAge = age;
		if(weight <= minWeight)
			minWeight = weight;
		if(height <= minHeight)
			minHeight = height;
		sumPersons++;
	}
	fclose(fhnd);
	avgAge = sumAge / sumPersons;
	avgWeight = sumWeight / sumPersons;
	avgHeight = sumHeight / sumPersons;
	
	printf("Keski-ikä: %f", avgAge);
	printf("\nKeskipaino: %f", avgWeight);
	printf("\nKeskipituus: %f", avgHeight);
	// and so on, and so on...
}


/* 3. lasketaan painoindeksi, ja kirjataan se tiedostoon
*/
void recordBMItoFile(char* fName, char* lName, int weight, int height)
{
	double bmi = weight / (height * height);
	FILE *fhnd = fopen("bmi.txt","a");
	fprintf("%s %s %f\n");
	fclose(fhnd);
}






