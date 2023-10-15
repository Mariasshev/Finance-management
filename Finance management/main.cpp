#include "Finance.h"
#include "Wallet.h"
#include "Card.h"
#include "Credit.h"
#include <iostream>
using namespace std;

void Menu()
{
	cout << "Welcome to our finance system!" << endl;
	cout << "[1] - Fill up a purse\n[2] - Top up your card\n[3] - Create a card\n[4] - Withdraw money\n[5] - Financial report\n[6] - Exit the program\n";
	cout << "Select operation: ";
}
void SelectOperation() {
	Finance* finance = nullptr;
	int choice;
	int userAsw;
	bool check = true;
	do
	{
		cin >> choice;
		switch (choice) {
		case 1:
			//finance = new Wallet();
			//finance->TopUp();
			break;
		case 2:
			break;
		case 3:
			cout << "Which card do you want to create? \n [1] - debit card\n [2] - credit card\n";
			cin >> userAsw;
			switch (userAsw)
			{
			case 1:

			default:
				break;
			}
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Try again" << endl;
			check = false;
			break;
		}
	} while (!check);
}

int main()
{
	Menu();
	SelectOperation();
}