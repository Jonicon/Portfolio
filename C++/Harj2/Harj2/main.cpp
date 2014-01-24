#include <iostream>
#include "dice.h"
#include "Counter.h"
#include "Inspector.h"

using namespace std;

int main(void) {
	Dice dice;
	Counter lesser, greater, i;
	Inspector inspector;
	
	dice.initialize();
	lesser.reset(); greater.reset(), i.reset();
	inspector.setLimits(0.0f, 0.5f);
	while (i.getCount() < 100) {
		if (inspector.isWithinLimits(dice.roll()))
			lesser.increase();
		else
			greater.increase();
		i.increase();
	} 
	cout << "Numbers less than 0.5:\t\t" << lesser.getCount() << endl;
	cout << "Numbers greater than 0.5:\t" << greater.getCount() << endl;

	system("pause");
	lesser.reset(); greater.reset(); i.reset();
	return 0;
}