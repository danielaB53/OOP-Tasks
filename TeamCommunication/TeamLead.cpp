#include "TeamLead.hpp"

TeamLead::TeamLead(const std::string& name, double salary) : Developer(name)
{
	setInitialSalary(salary);
	leader = this;
}

std::vector<Developer*> TeamLead::getTeam() const
{
	return this->team;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary)
{
	if (developer != nullptr)
	{
		this->team.push_back(developer);
		developer->setInitialSalary(salary);
		developer->setTeamLeader(*developer, this);
	}
}

void TeamLead::removeDeveloperFromTeam(const std::string& name)
{
	int vecLength = this->team.size();

	for (int i = vecLength - 1; i >= 0; i--)
	{
		if(this->team.at(i)->getName() == name)
		{
			this->team.at(i)->removeTeamLead();
			this->team.erase(team.begin() + i);
		}
	}
}

void TeamLead::increaseTeamSalariesBy(double amount)
{
	for (int i = 0; i < team.size(); i++)
	{
		this->team.at(i)->increaseSalary(amount);
	}
}

void TeamLead::decreaseTeamSalariesBy(double amount)
{
	for (int i = 0; i < team.size(); i++)
	{
		this->team.at(i)->decreaseSalary(amount);
	}
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
	this->leavingRequests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
	this->promotionRequests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests()
{
	for (int i = 0; i < leavingRequests.size(); i++)
	{
		for (int j = 0; j < team.size(); j++)
		{
			if(leavingRequests.at(i).getSender() == team.at(j)->getName())
			{
				team.at(j)->removeTeamLead();
				removeDeveloperFromTeam(team.at(j)->getName());
			}
		}
	}
	leavingRequests.clear();
}

void TeamLead::fulfillPromotionRequests()
{
	for (int i = 0; i < promotionRequests.size(); i++)
	{
		for (int j = 0; j < team.size(); j++)
		{
			if(promotionRequests.at(i).getSender() == team.at(j)->getName())
			{
				team.at(j)->increaseSalary(promotionRequests.at(i).getAmount());
			}
		}
	}
	promotionRequests.clear();
}
