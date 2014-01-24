#pragma once

#include "CounterObserver.h"
class LimitedCounter;
class CounterUser : public CounterObserver
{
public:
	CounterUser(int start, int limit);
	~CounterUser(void);
	void increaseBy(int n);
	virtual void handleLimitReached();
private:
	LimitedCounter* observable;
};

