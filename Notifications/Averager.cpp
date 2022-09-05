#include "Averager.hpp"

Averager::Averager(std::string id) : Subscriber(id)
{
}

void Averager::signal(Message message)
{
	this->values.push_back(message);
}

int Averager::read() const
{
	int total = 0;
	if (this->values.size() == 0)
		return 0;

	for (size_t i = 0; i < this->values.size(); i++)
	{
		total += this->values[i].data;
	}

	int average = total / this->values.size();

	return average;
}

Averager* Averager::copy() const
{
	return new Averager(*this);
}
