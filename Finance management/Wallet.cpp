#include "Finance.h"
#include "Wallet.h"
#include "Category.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <map>
#include <string>
using namespace std;

void Wallet::TopUp()
{
	double replenishment;
	do 
	{
		cout << "Add: ";
		cin >> replenishment;
		if (replenishment < 1) 
		{
			cout << "Incorrect sum! Try again!" << endl;
		}
	} while (replenishment < 1);
	curr_balance += replenishment;
	cout << "Success!" << endl;
	cout << "Your current balance: " << GetCurrBal() << "$" << endl;
}

void ShowCategory() {
}
void Wallet::EnterCosts()
{
	
	double costs;
	cout << "Enter costs: ";
	cin >> costs;
	if (costs > curr_balance) {
		cout << "It`s " << costs - curr_balance << "$ more than you have!" << endl;
	}
	else {
		string categoryName = ChooseCategory();
		if (category.find(categoryName) != category.end()) {
			category[categoryName] = costs;
			curr_balance -= costs;
			Print();
		}
		else {
			cout << "There is no such category" << endl;
		}
		
	}
	
}

void Wallet::Print()
{
	cout << "Your wallet: " << endl;
	cout << "Current balance: " << curr_balance << endl;
}

double Wallet::GetCurrBal()
{
	return curr_balance;
}

string Wallet::ChooseCategory()
{
	int choice;
	string categoryName;
	int count = 1;
	cout << "Categories: " << endl;
	cout << endl << endl;
	for (auto it = category.begin(); it != category.end(); it++) {
		cout << "\t[" << count++ << "] " << it->first << endl;
	}
	bool check = false;
	do {
		cout << "Choose a category: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			return categoryName = "Cafe";
			break;
		case 2:
			return categoryName = "Clothes";
			break;
		case 3:
			return categoryName = "Entertaiment";
			break;
		case 4:
			return categoryName = "Health";
			break;
		case 5:
			return categoryName = "Products";
			break;
		default:
			cout << "Wrong choice" << endl;
			check = false;
			break;
		}
	} while (!check);
	
}

void Wallet::ShowCategory()
{
	for (auto it = category.begin(); it != category.end(); it++) {
		cout << it->first << " ---- " << it->second << endl;
	}
}
