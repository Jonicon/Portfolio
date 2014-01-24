#include "VecPrint.h"
#include <iostream>

using namespace std;

VecPrint::VecPrint(void)
{
	i = 0;
}


VecPrint::~VecPrint(void)
{
}


void VecPrint::operator()(int n)
{
	cout << "Nro " << ++i << ": " << n << endl;
}
