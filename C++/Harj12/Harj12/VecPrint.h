#pragma once
class VecPrint
{
public:
	VecPrint(void);
	~VecPrint(void);
	void operator()(int n);
private:
	int i;
};

