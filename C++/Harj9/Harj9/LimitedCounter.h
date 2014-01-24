#pragma once
#include "counter.h"
#include "CounterUser.h"
#include <iostream>
class LimitedCounter : public Counter
{
public:
	LimitedCounter(const int start = 0, const int limit= 10000);
	~LimitedCounter(void);
	void setLimit(const int n);
	LimitedCounter operator++(int); // post
	virtual LimitedCounter& operator++(); // pre
	void setObserver(CounterObserver* o);
	void notify();
	
private:
	int limit;
	CounterObserver* observer;
};

