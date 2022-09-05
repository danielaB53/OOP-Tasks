#include "Semaphore.hpp"

Semaphore::Semaphore() : Counter(), TwowayCounter(), LimitedCounter(1), LimitedTwowayCounter(0, 1)
{
}

Semaphore::Semaphore(bool isMax) : Counter(), TwowayCounter(), LimitedCounter(1), LimitedTwowayCounter(0, 1)
{
	if(isMax == true)
	{
		this->counter = 1;
	}
	else 
	{
		this->counter = 0;
	}
}

bool Semaphore::isAvailable() const
{
	bool result = false;
	if (this->counter > 0)
		result = true;

	return result;
}

void Semaphore::wait()
{
	if (this->counter > 0)
		this->counter--;
}

void Semaphore::signal()
{
	if (this->counter < 1)
		this->counter++;
}
