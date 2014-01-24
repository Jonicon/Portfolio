#include "LimitedCounter.h"
#include <iostream>


LimitedCounter::LimitedCounter(int start = 0, int lim = 10000) : count(start)
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

void LimitedCounter::reset()
{
	count.reset();
}

int LimitedCounter::getCount() const
{
	return count.getCount();
}

LimitedCounter LimitedCounter::operator++(int) // post
{
	LimitedCounter old = *this;
	if (count < limit)
	{
		count++;
	}
	return old;
}

LimitedCounter LimitedCounter::operator++() // pre
{
	if(count < limit)
	{
		count++;
	}
	return *this;
}

ostream &operator<<(ostream &out, const LimitedCounter &c)
{
	out << c.count;
	return out;
}

bool LimitedCounter::operator<(const int i) const
{
	return count < i;
}