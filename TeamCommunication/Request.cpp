#include "Request.hpp"

Request::Request(const std::string& message, const std::string& sender) : message(message), messageSender(sender)
{
	objectCounter++;
	this->currentIDNumber = objectCounter;
}

std::string Request::getMessage() const
{
	return this->message;
}

std::string Request::getSender() const
{
	return this->messageSender;
}

int Request::getCount()
{
	return objectCounter;
}

int Request::getID() const
{
	return this->currentIDNumber;
}

int Request::objectCounter = 0;