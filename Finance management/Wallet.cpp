#include "Finance.h"
#include "Wallet.h"
#include "Category.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
using namespace std;

void Wallet::TopUp()
{
	double replenishment;
	do 
	{
		cout << "Add in wallet: ";
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

void Wallet::EnterCosts()
{
	int day, month;
	double costs;
	cout << "Enter costs: ";
	cin >> costs;
	if (costs > curr_balance)
	{
		cout << "It`s " << costs - curr_balance << "$ more than you have!" << endl;
	}
	else {
		//choose a category
		string categoryName = ChooseCategory();
		string date;
			cout << "Enter day: ";
			cin >> day;
			cout << "Enter month: ";
			cin >> month;
			inf.push_back(Category{ categoryName, day , month, costs});
			for (size_t i = 0; i < inf.size(); ++i) {
				for (size_t j = 0; j < inf.size(); ++j) {
					cout << "Category: " << inf[i].category << "\tCosts: " << inf[i].costs  << "\tDate: " << inf[i].day << "/" << inf[i].month << endl;
					i++;
				}
			}
			curr_balance -= costs;
			total_expanses +=costs;
			Print();
	}
}

void Wallet::Print()
{
	cout << "\t\t\t\tYour wallet: " << endl;
	cout << "\t\t\t\tCurrent balance: " << curr_balance << "$" << endl;
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
	ShowCategory();
	cout << endl << endl;

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
	cout << "[1] - Cafe" << endl;
	cout << "[2] - Clothes" << endl;
	cout << "[3] - Entertaiment" << endl;
	cout << "[4] - Health" << endl;
	cout << "[5] - Products" << endl;
}
