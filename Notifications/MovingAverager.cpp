#include "MovingAverager.hpp"

MovingAverager::MovingAverager(std::string id, size_t windowSize) : Subscriber(id), windowSize(windowSize)
{
}

void MovingAverager::signal(Message message)
{
	this->values.push_back(message);
}

int MovingAverager::read() const
{
	int total = 0;
	if (values.size() == 0)
		return 0;

	if (windowSize >= this->values.size() || windowSize == 0)
	{
		int average = 0;
		for (size_t i = 0; i < this->values.size(); i++)
		{
			average += values[i].data;
		}
		average /= this->values.size();
		return average;
	}
	
	for (size_t i = this->values.size() - windowSize - 1; i <= this->values.size(); i++)
	{
		total += this->values[i].data;
	}
	int averageWindowSize = total / windowSize;
	return averageWindowSize;
}

MovingAverager* MovingAverager::copy() const
{
	return new MovingAverager(*this);
}
