#include "dice.h"
#include <iostream>
#include <ctime>


Dice::Dice( void )
{

}


Dice::~Dice( void )
{

}

void Dice::initialize( void )
{
	srand(time(NULL));
}

float Dice::roll( void )
{
	return (float)rand()/(float)RAND_MAX;
}
