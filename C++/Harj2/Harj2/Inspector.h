#pragma once
class Inspector
{
public:
	Inspector(void);
	~Inspector(void);

	void setLimits(float l, float h);

	bool isWithinLimits(float f);


private:
	float low, high;
};

