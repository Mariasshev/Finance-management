#pragma once
#include <iostream>
#include "Category.h"
#include <vector>
#include <string>
using namespace std;

class Finance: public Category
{
protected:
	double curr_balance;
	double total_expanses;
	//an array for data (category, date, expanses)
	vector<Category> inf;
public:
	Finance() = default;
	
	//to top up a card or add cash to wallet
	virtual void TopUp()=0;	
	//enter costs 
	virtual void EnterCosts() = 0;
	//show
	virtual void Print();
	//to write report in file
	void ReportByCategory();			
	void RatingMax();
	double GetBalance();
};

