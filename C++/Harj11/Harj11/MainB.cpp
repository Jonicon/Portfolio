#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

template<typename T> 
void printVector( vector<T> const &vec);

int main (void)
{
	vector<int> allNumbers;
	vector<int> selectedNumbers;
	int arr[] = { 1, 2, 3, 5, 8, 13, 21 };
	vector<int> yourNumbers( arr, arr + sizeof(arr) / sizeof(arr[0]) );
	vector<int> inter(7);
	vector<int>::iterator it;
	
	srand (unsigned(time(NULL)) );
	for ( int i = 1; i < 38; ++i )
		allNumbers.push_back(i);

	random_shuffle( allNumbers.begin(), allNumbers.end() );
	selectedNumbers.assign( allNumbers.begin(), allNumbers.begin()+7 );
	sort( selectedNumbers.begin(), selectedNumbers.end() );
	it = set_intersection( selectedNumbers.begin(), selectedNumbers.end(), yourNumbers.begin(), yourNumbers.end(), inter.begin() );
	inter.erase( it, inter.end() );

	// results print-out
	cout << "Oikea lottorivi on : " << endl;
	printVector( selectedNumbers );

	cout << "Valitsemasi rivi oli: " << endl;
	printVector( yourNumbers );

	cout << "Oikein sait: " << inter.size() << " numeroa." << endl;
	printVector( inter );

	system("pause");
}


template<class T> 
void printVector( vector<T> const &vec )
{
	typename vector<T>::const_iterator it;
	for( it = vec.begin(); it != vec.end(); it++)
		cout << *it << endl;
}