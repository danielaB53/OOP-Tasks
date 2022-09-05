#pragma once

#include "LimitedTwowayCounter.hpp"

class Semaphore : virtual public LimitedTwowayCounter
{
public:
	Semaphore();
	Semaphore(bool isMax);
	
	bool isAvailable() const;
	void wait();
	void signal();
};
