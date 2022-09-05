#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(int max) : Counter(0), maxValue(max)
{
}

LimitedCounter::LimitedCounter(int max, int initial) : Counter(initial), maxValue(max)
{
}

LimitedCounter::LimitedCounter(int max, int initial, unsigned step) : Counter(initial, step), maxValue(max)
{
}

void LimitedCounter::increment()
{
	if((getTotal() + getStep())<= getMax())
	{
		Counter::increment();
	}
}

int LimitedCounter::getMax() const
{
	return this->maxValue;
}
