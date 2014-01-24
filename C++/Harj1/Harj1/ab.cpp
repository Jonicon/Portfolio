#include<iostream>

void coordInitDefault(double *d1, double *d2, double x = 0.0, double y = 0.0)
{
	*d1 = x;
	*d2 = y;
}


void coordInit(double &d1, double &d2, double x = 0.0, double y = 0.0)
{
	d1 = x;
	d2 = y;
}

void main(void)
{
	double d1;
	double d2;

	// Old C-style
	coordInitDefault(&d1, &d2);
	std::cout << d1 << ", " << d2 << std::endl;

	coordInitDefault(&d1, &d2, 1.0, 2.0);
	std::cout << d1 << ", " << d2 << std::endl;

	// Pass arguments by reference, newer C++ style
	coordInit(d1, d2);
	std::cout << d1 << ", " << d2 << std::endl;

	coordInit(d1, d2, 1.0, 2.0);
	std::cout << d1 << ", " << d2 << std::endl;

	// Just a pause before quit 
	fflush(stdin);
	printf("press any key to quit");
	getchar();
}