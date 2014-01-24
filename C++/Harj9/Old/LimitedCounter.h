#pragma once
#include "CounterUser.h"
#include "counter.h"
class LimitedCounter : public Counter
{
public:
	LimitedCounter(CounterUser obs, int start, int l);
	~LimitedCounter(void);
	void setObserver(CounterUser& o);
	void notify();
private:
	CounterUser& observer;
	int limit;
};

