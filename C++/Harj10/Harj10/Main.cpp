#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main (void)
{
	pair<int, pair <string, string>> pair1;
	pair<int, pair <string, string>> pair2;

	pair1 = make_pair(123, make_pair("aaaaa", "bbbbbb"));
	pair2 = make_pair(234, make_pair("dddd", "cccc"));

	cout << "no\t" << "first\t" << "second\t" << endl;
	cout << pair1.first << "\t" << pair1.second.first << "\t" <<  pair1.second.second << endl;
	cout << pair2.first << "\t" << pair2.second.first << "\t" <<  pair2.second.second << endl;

	system("pause");






	/***********

	Osa kaksi:

	***********/
	vector<string> v;
	string s, l = "";

	// otetaan inputtia
	while ( 1 )
	{
		cin >> s;
		if( s == "stop" )
			break;
		else
			v.push_back(s);
	}

	// etsit‰‰n pisin stringi
	for (int i = 0; i < v.size(); i++)
	{
		if (l.length() < sizeof(i))
			l = v[i];
	}

	// tulostuksia
	cout << "pisin string: " << l << endl << endl;
	cout << "muut stringit: " << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl << endl;

	//lis‰‰ tulostuksia
	cout << "vektorin size: " << v.size() << endl;
	cout << "vektorin capacity: " << v.capacity() << endl;
	cout << "sizeof(v): " << sizeof(v) << endl;

	system("pause");
}