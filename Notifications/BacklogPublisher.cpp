#include "BacklogPublisher.hpp"

BacklogPublisher::BacklogPublisher() : Publisher()
{
}

void BacklogPublisher::subscribe(Subscriber* newSubscriber)
{
	if(newSubscriber != nullptr)
	{
		this->subscribers.push_back(newSubscriber);
		if (this->subscribers.size() > 0)
		{
			for (size_t i = 0; i < previousMessages.size(); i++)
			{
				newSubscriber->signal(previousMessages[i]);
			}
		}
	}
}

void BacklogPublisher::unsubscribe(Subscriber* subscriberToBeRemoved)
{
	for (size_t i = 0; i < this->subscribers.size(); i++)
	{
		if (subscribers[i]->id == subscriberToBeRemoved->id)
		{
			subscribers.erase(subscribers.begin() + i);
		}
	}
}

void BacklogPublisher::signal(Message message)
{
	this->previousMessages.push_back(message);
	for (size_t i = 0; i < subscribers.size(); i++)
	{
		subscribers[i]->signal(message);
	}
}
