#pragma once
#include "Finance.h"

class Card :public Finance
{
protected:
	int amount_of_card;
	int limit;
public:
	void virtual EnterData()const = 0;
};

