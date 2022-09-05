#pragma once

#include "TwowayCounter.hpp"
#include "LimitedCounter.hpp"

class LimitedTwowayCounter : virtual public TwowayCounter, virtual public LimitedCounter
{
public:
	LimitedTwowayCounter(int min, int max);
	LimitedTwowayCounter(int min, int max, int initial);
	LimitedTwowayCounter(int min, int max, int initial, unsigned step);

	void decrement();
	int getMin() const;

private:
	int minValue;
};

