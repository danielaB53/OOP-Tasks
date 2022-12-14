#pragma once

#include "Developer.hpp"
#include <vector>

class TeamLead : public Developer
{
public:
	TeamLead(const std::string& name, double salary);

	std::vector<Developer*> getTeam() const;

	void addDeveloperToTeam(Developer* developer, double salary);
	void removeDeveloperFromTeam(const std::string& name);
	void increaseTeamSalariesBy(double amount);
	void decreaseTeamSalariesBy(double amount);
	void addLeavingRequest(const LeavingRequest& leavingRequest);
	void addPromotionRequest(const PromotionRequest& promotionRequest);
	void fulfillLeavingRequests();
	void fulfillPromotionRequests();

private:
	std::vector <Developer*> team;
	std::vector <LeavingRequest> leavingRequests;
	std::vector <PromotionRequest> promotionRequests;
};
