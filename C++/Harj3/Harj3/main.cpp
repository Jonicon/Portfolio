#include <iostream>
#include "String.h"

void f(String &s);

int main(void)
{
	String s("abcdefg");
	s.list();
	f(s);
	s.list();

	system("pause");
	delete &s;
	return 0;
}

void f(String &s)
{
	s.list();
}