#pragma once;
#include "Finance.h"

class Wallet :public Finance
{
private:
	double curr_balance;
public:
	virtual void TopUp();
	virtual void EnterCosts();
	virtual void Print();
};