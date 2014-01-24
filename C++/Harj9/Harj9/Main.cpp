#include <iostream>
#include "CounterUser.h"

int main (void)
{
	CounterUser u(0,5);
	for (int i=0; i<12; i++)
		u.increaseBy(1);

	system("pause");
}