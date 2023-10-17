#pragma once
#include <iostream>
#include "Category.h"
#include <vector>
#include <string>
using namespace std;


class Finance: public Category{
protected:
	double curr_balance;
	double total_expanses;
	vector<Category> arr;
public:
	Finance() = default;
	
	virtual void TopUp()=0;		//to top up a card or add cash to wallet
	virtual void EnterCosts()=0;		//enter costs 
	virtual void Print();
	double GetBalance();
	void WriteReportToFile();
	void RatingMax();
};

