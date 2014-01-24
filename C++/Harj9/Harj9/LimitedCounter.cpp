#include "LimitedCounter.h"
#include <iostream>


LimitedCounter::LimitedCounter(const int start , const int lim) : Counter(start)
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
	} else 
		notify();
	return old;
}

LimitedCounter& LimitedCounter::operator++() // pre
{
	if(Counter::getCount() < limit)
	{
		Counter::operator++();
	} else
		notify();
	return *this;
}

void LimitedCounter::setObserver(CounterObserver* o)
{
	observer = o;
}

void LimitedCounter::notify()
{
	observer->handleLimitReached();
}

