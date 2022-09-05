#pragma once

#include <string>
#include <vector>
#include "Message.hpp"

class Subscriber
{
public:
	Subscriber(std::string id = "");

	const std::string id;

	virtual void signal(Message message) = 0;
	virtual int read() const = 0;
	virtual Subscriber* copy() const = 0;
protected:
	std::vector <Message> values;
};
