#pragma once
class CounterObserver
{
public:
	CounterObserver(void);
	~CounterObserver(void);
	virtual void handleLimitReached();
};

