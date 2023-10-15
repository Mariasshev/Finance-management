#pragma once
#include "Wallet.h"
#include <iostream>
using namespace std;

class Finance{
protected:
	//Wallet wallet;
	double curr_balance;
	string date;
public:
	Finance() = default;
	virtual void TopUp();		//to top up a card or add cash to wallet
	virtual void EnterCosts();		//enter costs 
	virtual void Print();
};

