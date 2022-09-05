#pragma once

#include "Request.hpp"

class PromotionRequest : public Request
{
public:
	PromotionRequest(const std::string& sender, double amount);

	double getAmount() const;
private:
	double amount;
};

