#include "RoundupCounter.h"


RoundupCounter::RoundupCounter(unsigned int start, unsigned int n)
{
	limit = n;
}

RoundupCounter::~RoundupCounter(void)
{
}

void RoundupCounter::setLimit(const int n)
{
	limit = n;
}

RoundupCounter& RoundupCounter::operator++() //pre
{
	if (getCount() < limit)
	{
		Counter::operator++();
	}

	else 
	{
		Counter::reset();
	}
	return *this;
}

RoundupCounter RoundupCounter::operator++(int) //post
{
	RoundupCounter old = *this;
	if (getCount() < limit)
	{
		Counter::operator++();
	}
	
	else
	{
		Counter::reset();
	}
	return old;
}


