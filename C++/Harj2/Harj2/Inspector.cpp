#include "Inspector.h"


Inspector::Inspector(void)
{
	low = 0;
	high = 0;
}


Inspector::~Inspector(void)
{
}

void Inspector::setLimits(float l, float h)
	{
		low = l;
		high = h;
	}

bool Inspector::isWithinLimits(float f)
	{
		if ( f < high )
			return true;
		else
			return false;
	}
