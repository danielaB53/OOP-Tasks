#pragma once

#include "Message.hpp"
#include "Subscriber.hpp"
#include <string>

class MovingAverager : public Subscriber
{
public:
	MovingAverager(std::string id, size_t windowSize);

	const size_t windowSize;

	void signal(Message) override;

	int read() const override;

	MovingAverager* copy() const override;
};