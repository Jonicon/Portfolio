#pragma once
using namespace std;
#include <vector>
#include <time.h>

class RandGen
{
public:
	RandGen();
	~RandGen(void);
	int operator()();
private:
	vector<int> numbers;
};

