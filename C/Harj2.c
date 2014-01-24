/********************************
Joni Kontusalmi, Harkat osa 2:
*********************************/




// App begins
#include <stdio.h>

// prototypes
void printASCII();
void revPrintsStr(char *string);
char reverseString(char *string);
int findChar(char *string, const char c);
char *cleanString(char *string);



/***************************************************
	Definistions Begin
****************************************************/
 
/* 1. Kirjoita ohjelma, joka tulostaa kokonaislukuarvoja 0-255 vastaavat DOS-merkit ja niiden koodit 
10-, 8- ja 16-järjestelmässä.
*/
void printASCII()
{
	int i;
	for(i=0; i<255; ++i)
	{
		printf("&c\t%i\t%o\t%x", i,i,i,i);
	}
}

/* 2. Kirjoita ohjelma, joka pyytää käyttäjältä merkkijonon ja tulostaa sen takaperoisessa 
järjestyksessä so. lopusta alkuun
*/
void revPrintsStr(char *string)
{
	int i;
	for(i=strlen(string)-1; i>=0; --i)
	{
		printf("%c", string[i]);
	}
}

/* 3. Kijroita funktio, joka saa parametrinaan merkkijonon ja kääntää sen merkit päinvastaiseen 
järjestykseen. Funktio palauttaa arvonaan osoittimen merkkijonon alkuun. Kirjoita myös 
pääohjelma, joka kutsuu funktiota (esim. edellisen tehtävän ohjelman muunnos). 
*/
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

/*  4. Kirjoita funktio, joka etsii merkkijonosta tiettyä merkkiä. 
Funktiolle annetaan parametreina merkkijono ja merkki. Funktio palauttaa arvonaan merkkijonon 
ensimmäiseen sellaisen merkin indeksin, jota etsitään. Ellei etsittävää merkkiä löydy, funktio 
palauttaa arvon -1. Kirjoita funktiolle myös käyttöympäristö eli pääohjelma, josta kutsut sitä. 
*/
int findChar(char *string, const char c)
{
	int i;
	while (string[i] != c)
	{
		i++;
		if (i > strlen(string))
			return -1;
	}
	return i;
}


/*5. Kirjoita funktio, joka tiivistää tekstiä siten, että se poistaa parametrina annetusta merkkijonosta 
kaikki muut paitsi kirjaimenmerkit. Kaikki välilyönnit ja välimerkit siis poistetaan. Funktio 
palauttaa arvonaan muunnetun merkkijonon (osoittimen, joka osoittaa merkkijonon alkuun).
*/
char *cleanString(char *string)
{
	int i, j;
	char *newString = (char*)malloc(strlen(string)+1);
	for (i=0; i < strlen(string); i++)
	{
		if (isalpha(string[i]))
		{
			newString[j] = string[i];
			j++;
		}
	}
	newString[j] = '\0';
	free(string);
	return newString;
}





