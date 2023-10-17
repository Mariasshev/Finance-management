#pragma once
#include "Finance.h"
#include "Category.h"
#include <iostream>
using namespace std;

class Wallet: public Finance
{
private:
	double balance;
	
public:
	//top up the wallet
	void TopUp();
	//enter costs by choosen category
	void EnterCosts();
	//show all categories
	void ShowCategory();
	//choose a category from the list
	string ChooseCategory();
	void Print();
	double GetCurrBal(); 
};