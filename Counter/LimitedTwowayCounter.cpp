#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max) : Counter(), LimitedCounter(max), minValue(min)
{
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial) : Counter(initial),
TwowayCounter(initial), LimitedCounter(max, initial), minValue(min)
{
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned step) : Counter(initial, step),
	TwowayCounter(initial, step),LimitedCounter(max, initial, step), minValue(min)
{
}

void LimitedTwowayCounter::decrement()
{
	if ((getTotal() - getStep()) >= getMin())
	{
		TwowayCounter::decrement();
	}
}

int LimitedTwowayCounter::getMin() const
{
	return this->minValue;
}
