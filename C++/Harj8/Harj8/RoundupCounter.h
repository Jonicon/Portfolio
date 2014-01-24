#pragma once
#include "counter.h"
#include <iostream>
class RoundupCounter : public Counter
{
public:
	RoundupCounter(unsigned int start = 0, unsigned int n = 0);
	~RoundupCounter(void);
	void setLimit(const int n);
	virtual RoundupCounter& operator++(); //pre
	RoundupCounter operator++(int); //post
private:
	int limit;
};



