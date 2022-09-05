#pragma once

#include <string>
#include "Request.hpp"
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"

class TeamLead;

class Developer
{
public:
	Developer(const std::string& name);

	std::string getName() const;
	double getSalary() const;
	TeamLead* getTeamLead() const;

	void setInitialSalary(double amount);
	void sendLeavingRequest();
	void sendPromotionRequest(double amount);

	void increaseSalary(double amount);
	void decreaseSalary(double amount);
	void removeTeamLead();
	void setTeamLeader(Developer& developer, TeamLead* newLeader);

protected:
	std::string name;
	double salary;
	TeamLead* leader;
};
