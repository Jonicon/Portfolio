#include "LimitedCounter.h"


LimitedCounter::LimitedCounter(CounterUser obs, int start = 0, int l = 0) : observer(obs), Counter(start)
{
	limit = l;
}


LimitedCounter::~LimitedCounter(void)
{
}

void LimitedCounter::setObserver(CounterUser& o)
{
	observer = o;
}

void LimitedCounter::notify()
{
	observer.handleLimitReached();
}