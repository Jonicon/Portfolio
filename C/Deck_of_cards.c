

int main (int argc, char **argv)
{
	char* string;
	char ws = " ";
	int i, j;
	
	for (i=1; i<argc; i++)
	{
		string = (char*)malloc(strlen(*argv[i]));
		string = *argv[i];
		for(j=0, j<strlen(string); j++)
		{
			printf("%X ", string[j]);
		}
		printf("%X ", ws);
		free(string);
	}
}

/***************************************
	Korttipakka, nostetaan n määrä kortteja pakasta
	Tulostetaan kortit ja korttien yhteispistemäärä
*****************************************/

#define MAX_CARDS 56

enum Land
{
	CLUBS, SPADES, DIAMONDS, HEARTS
};

const char* lands[4] 
{
	" Clubs"," Spades"," Diamonds"," Hearts"
};

typedef struct
{
	enum Land land;
	int value;
} Card;

typedef struct
{
	Card d[MAX_CARDS];
}Deck;

Deck createDeck()
{
	Deck deck;
	deck = (Deck*)malloc(sizeof(Deck));
	int i, l, val;
	for(i=0; i<MAX_CARDS; i++)
	{
		l = i % 4;
		val = i % 14 + 1;
		deck.d[i] = createCard(enum Land[l], int val);
	}
	return deck;
}

Card* createCard(enum Land l, int v)
{
	Card* c;
	c = (Card*)malloc(sizeof(Card));
	c->land = l;
	c->value = v;
	return c;
}

void printCard(Card *c)
{
	printf("%d %s\n", c->value, lands[c->land]);
}

void drawNRandom(int n, Deck *d)
{
	int i, sum=0;
	Card* c;
	for(i=0, i<n; i++)
	{
		c = d[rand() % MAX_CARDS];
		sum += c->value;
		printCrad(c);
	}
	printf("Sum of value: %d", sum);
}