#include "Counter.h"


Counter::Counter( void )
{
	c = 0;
}


Counter::~Counter( void )
{
}

void Counter::increase()
{
	c++;
}

int Counter::getCount()
{
	return c;
}

void Counter::reset()
{
	c = 0;
}
