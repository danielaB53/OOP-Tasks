#pragma once

#include"Publisher.hpp"

class SimplePublisher : public Publisher
{
public:
	
	SimplePublisher();
	
	void subscribe(Subscriber*) override;

	void unsubscribe(Subscriber*) override;
	
	void signal(Message) override;

};
