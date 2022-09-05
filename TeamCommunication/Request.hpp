#pragma once

#include <string>

class Request
{
public:
	Request(const std::string& message, const std::string& sender);

	std::string getMessage() const;
	std::string getSender() const;
	static int getCount();
	int getID() const;

protected:
	std::string message;
	std::string messageSender;
	static int objectCounter;
	int currentIDNumber;
};
 

