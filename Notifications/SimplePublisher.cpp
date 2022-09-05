#include "SimplePublisher.hpp"

SimplePublisher::SimplePublisher() : Publisher()
{
}

void SimplePublisher::subscribe(Subscriber* newSubscriber)
{
	if (newSubscriber != nullptr)
	{
		this->subscribers.push_back(newSubscriber);
	}
}

void SimplePublisher::unsubscribe(Subscriber* subscriberToBeRemoved)
{
	if (!subscriberToBeRemoved)
		return;
	for (size_t i = 0; i < this->subscribers.size(); i++)
	{
		if (subscribers[i]->id == subscriberToBeRemoved->id)
		{
			subscribers.erase(subscribers.begin() + i);
		}
	}
}

void SimplePublisher::signal(Message message)
{
	for (size_t i = 0; i < subscribers.size(); i++)
	{
		subscribers[i]->signal(message);
	}
}
