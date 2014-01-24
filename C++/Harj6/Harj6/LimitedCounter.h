#pragma once
#include "counter.h"
#include <iostream>
class LimitedCounter
{
public:
	LimitedCounter(int start, int limit= 10000);
	~LimitedCounter(void);
	void setLimit(const int n);
	void reset();
	int getCount() const;

	LimitedCounter operator++(int); // post
	LimitedCounter operator++(); // pre
	friend ostream &operator<<(ostream &out, const LimitedCounter &c);
	bool operator<(const int i) const;
private:
	Counter count;
	int limit;
};

