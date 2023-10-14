#pragma once
#include <iostream>
using namespace std;

class Finance
{
protected:
	//Wallet wallet;
	string date;
public:
	virtual void TopUp() const = 0;		//to top up a card or add cash to wallet
	virtual void EnterCosts() const = 0;		//enter costs 
	virtual void Print() = 0;
	void ShowAllInf();		//read information from file
};

