#include "Debit.h"
#include <string>
using namespace std;

int Card::amount_of_card = 0;
void Debit::EnterData()
{
	cout << "Enter fio: ";
	cin.ignore();
	getline(cin, this->fio);
	cout << "Your phone number: ";
	cin >> this->phone;
	cout << "Create a pin: ";
	int pincode;
	cin >> pincode;
	pin[amount_of_card] = pincode;
	cout << "Choose a payment system\n[1] - visa\n[2] - mastercard\n";
	int payment;
	bool check = true;
	cin >> payment;
	do {
		switch (payment)
		{
		case 1:
			paymentSystem[amount_of_card] =  "visa";
			break;
		case 2:
			paymentSystem[amount_of_card] = "matercard";
			break;
		default:
			cout << "Incorrect choice. Try again" << endl;
			check = false;
			break;
		}
	} while (!check);
	this->curr_balance = 0;
	Card::amount_of_card++;
}

void Debit::Print()
{
	for (int i = 0; i < amount_of_card; i++) {
		cout << "Your " << i+1 << " card: " << endl;
		cout << "System payment: " << paymentSystem[i] << endl;
		cout << "Balance: " << this->GetBalance() << "$" << endl;
		cout << "-------------------------" << endl;
	}
}

void Debit::TopUp()
{
	double sum;
	cout << "Your balance: " << this->GetBalance() << endl;
	cout << "Enter sum: ";
	cin >> sum;
	if (sum < 0) {
		cout << "Error" << endl;
	}
	else {
		this->curr_balance += sum;
		cout << "Your balance: " << curr_balance << endl;
	}
}

string Debit::ChooseCategory()
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


void Debit::EnterCosts()
{
	int pinCheck;
	double costs;
	cout << "Enter pin: ";
	cin >> pinCheck;
	for (int i = 0; i < amount_of_card; i++) {
		if (pinCheck == pin[i]) {
			cout << "access is open!" << endl;
			cout << "Enter costs: ";
			cin >> costs;
			if (costs > curr_balance) {
				cout << "It`s " << costs - curr_balance << "$ more than you have!" << endl;
			}
			else 
			{
				string categoryName = ChooseCategory();
				if (category.find(categoryName) != category.end()) 
				{
					category[categoryName] = costs;
					curr_balance -= costs;
					Print();
				}
				else 
				{
					cout << "There is no such category" << endl;
				}

			}
		}
	}
}
