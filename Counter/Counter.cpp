#include "Counter.hpp"

Counter::Counter() : counter(0), step(1)
{
}

Counter::Counter(int initial) : counter(initial), step(1)
{
}

Counter::Counter(int initial, unsigned step) : counter(initial), step(step)
{
}

void Counter::increment()
{
	(this->counter) += (this->step);
}

int Counter::getTotal() const
{
	return this->counter;
}

int Counter::getStep() const
{
	return this->step;
}
