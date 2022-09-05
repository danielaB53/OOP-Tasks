#pragma once

#include <vector>
#include "Subscriber.hpp"
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "Message.hpp"

class Publisher
{
public:
	Publisher() = default; 

	virtual void subscribe(Subscriber*) = 0;
	virtual void unsubscribe(Subscriber*) = 0;
	virtual void signal(Message) = 0;

	virtual ~Publisher() = default;

protected:
	std::vector<Subscriber*> subscribers;
};
