#include "Repository.hpp"

Repository::Repository()
{
}

Repository::Repository(const Repository& other)
{
	if(&other != nullptr)
	{
		copySubscribers(other.differentSubscribers);
	}
}

Repository& Repository::operator=(const Repository& rhs)
{
	if(this != &rhs)
	{
		deleteSubscribers();
		copySubscribers(rhs.differentSubscribers);
	}
	return *this;
}

Repository::~Repository()
{
	deleteSubscribers();
}

void Repository::add(Subscriber* newSubscriber)
{
	if(newSubscriber!=nullptr)
	{
		this->differentSubscribers.push_back(newSubscriber->copy());
	}
}

Subscriber* Repository::get(const std::string& id)
{
	for (size_t i = 0; i < this->differentSubscribers.size(); i++)
	{
		if (differentSubscribers[i]->id == id)
			return differentSubscribers[i];
	}
	return nullptr;
}

void Repository::copySubscribers(std::vector<Subscriber*> from)
{
	for (size_t i = 0; i < from.size(); i++)
	{
		this->differentSubscribers.push_back(from[i]->copy());
	}
}

void Repository::deleteSubscribers()
{
	for (size_t i = 0; i < this->differentSubscribers.size(); i++)
	{
		delete differentSubscribers[i];
	}
	this->differentSubscribers.clear();
}
