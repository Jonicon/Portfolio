#include "String.h"
#include <iostream>

using namespace std;

int main() {
	// vaihe 1.
	String s("abcdefg");
	cout  << s++ << endl;
	cout << ++s << endl;
	
	// vaihe 2.
	String s2("abcdefg");
	for (int i = 0 ; i < 7 ; i++)
	cout << s2[i] << " " ;
	s2[4] = 'X';
	for (int i = 0 ; i < 7 ; i++)
		cout << s2[i] << " " ;
	cout << endl;

	//3. vaihe
	String s3;
	char name[30];
	s3 = "Matti"; //C-style string -> String object
	cout << s3;
	strcpy(name, s3); //String object -> C-style string
	cout << name; 

	system("pause");
	} 