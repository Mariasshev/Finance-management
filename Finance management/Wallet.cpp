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

void Wallet::EnterCosts()
{
	int day, month;
	double costs;
	cout << "Enter costs: ";
	cin >> costs;
	if (costs > curr_balance) {
		cout << "It`s " << costs - curr_balance << "$ more than you have!" << endl;
	}
	else {
		string categoryName = ChooseCategory();
		//cin.ignore();
		//cout << "Enter category: ";
		//getline(cin, categoryName);
		string date;
			cout << "Enter day: ";
			cin >> day;
			cout << "Enter month: ";
			cin >> month;
			arr.push_back(Category{ categoryName , day , month, costs, type="wallet"});
			for (size_t i = 0; i < arr.size(); ++i) {
				for (size_t j = 0; j < arr.size(); ++j) {
					cout << "Category: " << arr[i].category << "\tCosts: " << arr[i].costs  << "\tDate: " << arr[i].day << "/" << arr[i].month <<"\tType: "<< arr[i].type<< endl;
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
	cout << "Your wallet: " << endl;
	cout << "Current balance: " << curr_balance << "$" << endl;
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
