#pragma once

#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"

class Repository {
public:
	
	Repository();
	Repository(const Repository& other);
	Repository& operator=(const Repository& rhs);
	~Repository();

	void add(Subscriber*);

	Subscriber* get(const std::string& id);

private:
	std::vector<Subscriber*> differentSubscribers;
	void copySubscribers(std::vector<Subscriber*> from);
	void deleteSubscribers();
};