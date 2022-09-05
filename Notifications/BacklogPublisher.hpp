#pragma once

#include "Publisher.hpp"

class BacklogPublisher : public Publisher
{
public:
	
	BacklogPublisher();
	
	void subscribe(Subscriber*) override;
	
	void unsubscribe(Subscriber*) override;

	void signal(Message) override; 

private:
	std::vector <Message> previousMessages;
};