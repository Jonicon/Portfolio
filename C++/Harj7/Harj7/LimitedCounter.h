#pragma once
#include "counter.h"
#include <iostream>
class LimitedCounter : public Counter
{
public:
	LimitedCounter(int start = 0, int limit= 10000);
	~LimitedCounter(void);
	void setLimit(const int n);

	LimitedCounter operator++(int); // post
	LimitedCounter& operator++(); // pre
private:
	int limit;
};

