#include "CounterUser.h"
#include "LimitedCounter.h"
#include <iostream>


CounterUser::CounterUser(int start, int limit) 
{
	observable = new LimitedCounter(start, limit);
	observable->setObserver(this);
}


CounterUser::~CounterUser(void)
{
}

void CounterUser::increaseBy(int n)
{
	for(int i = 0; i < n; i++)
	{
		observable->operator++();
		// ++(*observable)
	}
}

void CounterUser::handleLimitReached()
{
	std::cout << "Limit reached!" << std::endl;
	observable->reset();
}