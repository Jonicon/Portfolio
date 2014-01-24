#include "RandGen.h"


RandGen::RandGen(): numbers()  
{ 
	srand(unsigned(time(NULL))); 
}


RandGen::~RandGen(void)
{
}

int RandGen::operator()()
{
	int number;
	do  {
        number = rand() % 37 + 1;
    } while (find( numbers.begin(), numbers.end(), number) != numbers.end() );
	numbers.push_back(number);
    return number;
}
