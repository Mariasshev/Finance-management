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

	void TopUp();
	void EnterCosts();
	void Print();
	double GetCurrBal(); 
	void ShowCategory();
	string ChooseCategory();

};