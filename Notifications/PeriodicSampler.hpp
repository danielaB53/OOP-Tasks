#pragma once

#include "Message.hpp"
#include "Subscriber.hpp"
#include <string>

class PeriodicSampler : public Subscriber
{
public:
	PeriodicSampler(std::string id, size_t period);
	
	void signal(Message message) override;

	int read() const override;

	PeriodicSampler* copy() const override;

private:
	size_t period;
	std::vector<Message*> periodicData;
};