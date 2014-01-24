#include <iostream>
#include "String.h"

using namespace std;


int main (void)
{

	String s1("abcedf"); 
    String s2("ghijklmn");
    String sum;

    cout << "String 1 is:" << s1 << endl;
    cout << "String 2 is:" << s2 << endl;
		
    sum  = s1 + s2;     

    cout << "Sum is :" << sum << endl; // output should be 
                                    // abcdefghijklmn
    // Myös seuraavan pitäisi toimia
    sum = sum;
    cout << "Sum is still :" << sum; // output should 
                                    // still be abcdefghijklmn
	system("pause");
}

