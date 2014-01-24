/********************************
Joni Kontusalmi, Harkat osa 3:
*********************************/




// App begins
#include <stdio.h>

// prototypes
void lowerToUpper(char* string);
int findChar(const char *string, const char *c);
void stringAnalyzer(char *string);
char* reverseString(char *string);
int checkForPalindrome(const char* string);

// main begins
int main(int argc, char** argv)
{
	int a = atoi(argv[1]), b = atoi(argv[3]);
	char** op;
	strcpy(op, argv[2]);
	
	if (op == '+')
		printf("%d + %d = %d", a, b, op, a+b);
	if (op == '-')
		printf("%d + %d = %d", a, b, op, a-b);
	if (op == 'x')
		printf("%d + %d = %d", a, b, op, a*b);
	
	system("pause");
	return 0;
}

/***************************************************
	Definistions Begin
****************************************************/

/*1. 
Kirjoita ohjelma, joka saa komentoriviparametreinaan kokonaislukujen laskutoimituksen ja 
tulostaa lopputuloksen
*/
/*****************************************
		Katso main();
********************************************/
		
/*2. Kirjoita funktio, joka muuttaa parametrina annetun merkkijonon kaikki kirjainmerkit isoiksi 
kirjaimiksi. Ota huomioon myös ns. skandinaaviset merkit. Muut merkit kuin kirjaimet jäävät 
ennalleen.
*/
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
int findChar(const char *string, const char *c)
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


/*3,  kuinka monta 
-merkkiä
-ei-tyhjää
-vokaalia
-isoa
-numeroa
-skandia strinkissä on
*/
void stringAnalyzer(char *string)
{
	int i;
	int chars=0, nonEmpty=0, vowels=0, capitals=0, numerics=0, skands=0;
	for (i = 0; i < strlen(string); i++)
	{
		if (string[i] > 32)
			chars++;
		else if( fincChar("EYUIOAÖÄeyuioaöä", string[i]) )
			vowels++;
		else if(!isspace(string[i]) )
			nonEmpty++;
		else if (string[i] >= 65 && string[i] <= 90)
			capitals++;
		else if(string[i] == 142 || string[i] == 153)
		{
			capitals++;
			skands++;
		}
		else if (string[i] == 132 || string[i] == 148)
			skands++;
	}
}

/*kirjan nimi 
• tekijä 
• kustantaja 
• painovuosi 
• sivumäärä 
• hinta 
• onko kuvitusta 
• ISBN-numero 
*/
typedef enum { false, true } bool;
typedef struct {
	char* name;
	char* author;
	short unsigned int printYear;
	short unsigned int pageCount;
	double priceEur;
	bool containsPics;
	unsigned int ISBN;
} Book;


/*****************************************
	tätä tarvitaan kohta
****************************************/
char* reverseString(char *string)
{
	int i, j;
	char temp;
	for(i=0, j=strlen(string)-1; i<j; ++i, --j)
	{
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;
	}
	return string;
}

/*5. Kirjoita ohjelma, joka tutkii onko syötteenä annettu merkkijono palindromi
*/

int checkForPalindrome(const char* string)
{
	int i, j;
	char* copy = (char*)malloc(strlen(string));
	char* copyRev = (char*)malloc(strlen(string));
	strcoy(copy, string);
	copyRev = reverserString(copy);
	
	for (i = 0, j = 0; i < strlen(string), j < strlen(string); i++, j++)
	{
		if (copy[i] != copyRev[j])
			printf("Vituiks män!");
			return 1;
	}
	free(copy);
	free(copyRev);
	return 0;
}