#include <iostream>
#include "LimitedCounter.h"
#include "RoundupCounter.h"

void useCounter(Counter& c, int n);

int main (void)
{
	LimitedCounter l(0, 5);
	RoundupCounter r(0, 5);

	useCounter(l, 8);
	useCounter(r, 8);
	cout << l.getCount() << endl;
	cout << r.getCount() << endl;
	system("pause");
}

void useCounter(Counter& c, int n)
{
	for(int i=0; i < n; i++)
	{
		++c;
	}
}