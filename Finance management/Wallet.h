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
	
	//Wallet() = default;
	virtual void TopUp();
	void EnterCosts();
	virtual void Print();
	double GetCurrBal(); 
	void ShowCategory();
	string ChooseCategory();
	/*void ShowDate() {
		for (auto it = date.begin(); it != date.end(); it++) {
			cout << it->first << "/" << it->second << endl;
		}
	}*/
};