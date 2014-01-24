#include <iostream>
#include "LimitedCounter.h"

int main (void) {
	LimitedCounter limCounter(0, 5); //alkuarvo 0 ja yläraja 5
	cout << limCounter++ << endl;
	cout << ++limCounter << endl;
	for (int i = 0; i < 9 ; i++)  {
		limCounter++;
		cout << limCounter << endl;
	}
	limCounter.reset();
	cout << limCounter.getCount() << endl;
	cout << (limCounter < 0);   // Testataan vertailuoperaattori näin

	system("pause");
}