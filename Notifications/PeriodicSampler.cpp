#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(std::string id, size_t period) : Subscriber(id), period(period)
{
}

void PeriodicSampler::signal(Message message)
{
	this->values.push_back(message);
	
	if (period != 0 && (this->values.size() - 1) % period == 0)
	{
		this->periodicData.push_back(&message);
	}
}

int PeriodicSampler::read() const
{
	if (period == 0)
		return 0;

	else if (periodicData.size() == 0)
		return 0;

	else
		return this->periodicData[this->periodicData.size() - 1]->data;
}

PeriodicSampler* PeriodicSampler::copy() const
{
	return new PeriodicSampler(*this);
}

