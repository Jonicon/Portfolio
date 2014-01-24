#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool strComp (const string& s1, const string& s2)
{
	return s1.length() < s2.length(); 
}

int main (void)
{
	vector<string> v;
	string s, longest;

	// otetaan inputtia
	while ( 1 )
	{
		cin >> s;
		if( s == "stop" )
			break;
		else
			v.push_back(s);
	}

	// tulostuksia
	cout << "pisin string: " << *max_element(v.begin(), v.end(), strComp) << endl << endl;

	cout << "muut stringit: " << endl;
	for (vector<string>::iterator i = v.begin(); i != v.end(); i++)
		cout << *i << endl << endl;

	//lisää tulostuksia
	cout << "v.size():\t" << v.size() << endl;
	cout << "v.capacity():\t" << v.capacity() << endl;
	cout << "sizeof(v):\t" << sizeof(v) << endl;

	system("pause");
}