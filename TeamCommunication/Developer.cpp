#include "Developer.hpp"
#include "TeamLead.hpp"

Developer::Developer(const std::string& name) : name(name), salary(0.0), leader(nullptr)
{
}

std::string Developer::getName() const
{
	return this->name;
}

double Developer::getSalary() const
{
	return this->salary;
}

TeamLead* Developer::getTeamLead() const
{
	return this->leader;
}

void Developer::setInitialSalary(double amount)
{
	if(this->salary == 0.0)
	{
		this->salary = amount;
	}
}

void Developer::sendLeavingRequest()
{
	if (leader != nullptr)
	{
		this->leader->addLeavingRequest(LeavingRequest(this->name));
	}
}

void Developer::sendPromotionRequest(double amount)
{
	if (leader != nullptr)
	{
		this->leader->addPromotionRequest(PromotionRequest(this->name, amount));
	}
}

void Developer::increaseSalary(double amount)
{
	this->salary += amount;
}

void Developer::decreaseSalary(double amount)
{
	this->salary -= amount;
}

void Developer::removeTeamLead()
{
	this->leader = nullptr;
}

void Developer::setTeamLeader(Developer& developer, TeamLead* newLeader)
{
	developer.leader = newLeader;
}
