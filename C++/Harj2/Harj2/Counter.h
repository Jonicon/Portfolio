#pragma once
class Counter
{
public:
	Counter( void );
	~Counter( void );

	void increase();
	int getCount();
	void reset();

private:
	int c;
};

