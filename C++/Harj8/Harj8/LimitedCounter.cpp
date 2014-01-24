#include "LimitedCounter.h"
#include <iostream>


LimitedCounter::LimitedCounter(int start , int lim) : Counter(start)
{
	limit = lim;
}


LimitedCounter::~LimitedCounter(void)
{
	
}

void LimitedCounter::setLimit(const int n)
{
	limit = n;
}

LimitedCounter LimitedCounter::operator++(int) // post
{
	LimitedCounter old = *this;
	if (Counter::getCount() < limit)
	{
		Counter::operator++();
	}
	return old;
}

LimitedCounter& LimitedCounter::operator++() // pre
{
	if(Counter::getCount() < limit)
	{
		Counter::operator++();
	}
	return *this;
}

