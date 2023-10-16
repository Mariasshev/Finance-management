#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef pair<string, double> myPair;

class Finance{
protected:
	double curr_balance;
	string date;
	map<string, double> category = 
	{
		{"Products", 0.0},
		{"Cafe", 0.0},
		{"Entertaiment", 0.0},
		{"Health", 0.0},
		{"Clothes", 0.0}
	};
	/*map<string, double> initcategories = {
		{"Products", 0.0},
		{"Cafe", 0.0},
		{"Entertaiment", 0.0},
		{"Health", 0.0},
		{"Clothes", 0.0}
	};*/
public:
	Finance() = default;
	
	virtual void TopUp()=0;		//to top up a card or add cash to wallet
	virtual void EnterCosts()=0;		//enter costs 
	virtual void Print();
	double GetBalance() {
		return curr_balance;
	}
};

