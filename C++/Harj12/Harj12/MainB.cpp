#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include "RandGen.h"
#include "VecPrint.h"

using namespace std;


void myPrint(int elem)
{
	cout << elem << " ";
}

int main (void)
{
	vector<int> selectedNumbers(7);
	int arr[] = { 1, 2, 3, 5, 8, 13, 21 };
	vector<int> yourNumbers( arr, arr + sizeof(arr) / sizeof(arr[0]) );
	vector<int> inter;
	ostream_iterator<int> out_it (cout," ");
	RandGen randGen;
	VecPrint selectedPrint;
	
	generate_n(selectedNumbers.begin(), 7, randGen);
	sort( selectedNumbers.begin(), selectedNumbers.end() );
	set_intersection( selectedNumbers.begin(), selectedNumbers.end(), yourNumbers.begin(), yourNumbers.end(), back_inserter(inter) );

	// results print-out
	cout << "Oikea lottorivi on : " << endl;
	for_each(selectedNumbers.begin(), selectedNumbers.end(), selectedPrint ); // "uusi" tyyli Funktio Oliolla
	cout << endl;

	cout << "Valitsemasi rivi oli: " << endl;
	for_each(yourNumbers.begin(), yourNumbers.end(), myPrint); 
	cout << endl;

	cout << "Oikein sait: " << inter.size() << " numeroa." << endl;
	copy(inter.begin(), inter.end(), out_it);	// "vanha" tyyli
	cout << endl;

	system("pause");
}
