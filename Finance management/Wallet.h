#pragma once
#include "Finance.h"
#include "Category.h"
#include <iostream>
using namespace std;

class Wallet: public Finance
{
private:
	//map<string, Category> categories;
public:
	
	//Wallet() = default;
	virtual void TopUp();
	void EnterCosts();
	virtual void Print();
	double GetCurrBal(); 
	void ShowCategory();
	string ChooseCategory();
	//void AddCategory(const string& categoryName);
};