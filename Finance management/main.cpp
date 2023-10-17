#include "Finance.h"
#include "Wallet.h"
#include "Card.h"
#include "Debit.h"
#include "Credit.h"
#include "Category.h"
#include <iostream>
#include <vector>
using namespace std;

void Menu()
{
	cout << "\n\n\n\t\t\t\t     Welcome to your finance system!" << endl << endl;
	cout << "\t\t\t\t\t[1] - Fill up a purse\n";
	cout << "\t\t\t\t\t[2] - Top up your card\n";
	cout << "\t\t\t\t\t[3] - Create a card\n";
	cout << "\t\t\t\t\t[4] - Withdraw money\n";
	cout << "\t\t\t\t\t[5] - Financial report\n";
	cout << "\t\t\t\t\t[6] - Exit the program\n\n";

	cout << "\t\t\t\t\tSelect operation: ";
}

void SelectOperation(Card* debit, Card* credit, Wallet wallet) {
	int choice, choice4, choice4_1, choice5, choice5_1, userAsw;			//for switch
	bool check2 = true, check = true, check4 = true;						//check user answer
	do
	{
		Menu();
		cin >> choice;
		switch (choice) {
		case 1:
			system("CLS");
			wallet.TopUp();
			break;
		case 2:
			system("CLS");
			do 
			{
				cout << "\n\n\t\t\t\t\tTop up: \n\n\t\t\t\t\t[1] - debit card\n\n\t\t\t\t\t[2] - credit card\n";
				cout << "\n\n\t\t\t\t\t(your answer): ";
				cin >> choice4;
				switch (choice4) {
				case 1:
					if (debit->GetAmountOfCard() > 1)
					{
						cout << "\n\n\t\t\t\t\tYou have " << debit->GetAmountOfCard() << " debit cards. Choose one card: " << endl;
						debit->Print();
						cout << endl;
						do {
							cout << "\n\n\t\t\t\t\t(your answer): ";
							cin >> choice4_1;
							switch (choice4_1)
							{
							case 1:
								debit[0].TopUp();
								break;
							case 2:
								debit[1].TopUp();
								break;
							case 3:
								debit[2].TopUp();
								break;
							default:
								cout << "\n\n\t\t\t\t\tWrong choice!" << endl;
								check4 = false;
								break;
							}
						} while (!check4);
					}
					if (debit->GetAmountOfCard() == 0) {
						cout << "\n\n\t\t\t\t\tYou don`t have a debit card!" << endl;
					}
					if (debit->GetAmountOfCard() == 1) {
						debit->TopUp();
					}
					break;
				case 2:
					if (credit->GetAmountOfCard() > 1)
					{
						cout << "\n\n\t\t\t\t\tYou have " << credit->GetAmountOfCard() << " credit cards. Choose one card: " << endl;
						debit->Print();
						cout << endl;
						do {
							cout << "\n\n\t\t\t\t\t(your answer): ";
							cin >> choice4_1;
							switch (choice4_1)
							{
							case 1:
								credit[0].TopUp();
								break;
							case 2:
								credit[1].TopUp();
								break;
							case 3:
								credit[2].TopUp();
								break;
							default:
								cout << "\n\n\t\t\t\t\tWrong choice!" << endl;
								check4 = false;
								break;
							}
						} while (!check4);
					}
					if (credit->GetAmountOfCard() == 0) {
						cout << "\n\n\t\t\t\t\tYou don`t have a credit card!" << endl;
					}
					if (credit->GetAmountOfCard() == 1) {
						credit->TopUp();
					}
					break;
				default:
					check2 = false;
					break;
				}
			} while (!check2);
			break;
		case 3:
			system("CLS");
			cout << "\n\n\n\t\t\t\t\tWhich card do you want to create? \n\t\t\t\t\t[1] - debit card\n\t\t\t\t\t[2] - credit card\n";
			check2 = true;
			do {
				cout << "\n\n\t\t\t\t\t(your answer): ";
				cin >> userAsw;
				switch (userAsw)
				{
				case 1:
					if (debit->GetAmountOfCard() > 3) {
						cout << "\n\n\t\t\t\t\tExceeding the limit of debit cards!" << endl;
					}
					else {
						debit->EnterData();
						debit->Print();
					}
					break;
				case 2:
					if (credit->GetAmountOfCard() > 3) {
						cout << "\n\n\t\t\t\t\tExceeding the limit of credit cards!" << endl;
					}
					else {
						credit->EnterData();
						credit->Print();
					}
					break;
				default:
					cout << "\n\n\t\t\t\t\tIncorrect choice" << endl;
					check2 = false;
					break;
				}
			} while (!check2);
			break;
		case 4:
			system("CLS");
			do {
				cout << "\n\n\n\t\t\t\t\tWithdraw money from: \n\t\t\t\t\t [1] - wallet \n\t\t\t\t\t [2] - debit card\n\t\t\t\t\t [3] - credit card";
				cout << "\n\n\t\t\t\t\t(your answer): ";
				cin >> choice4;
				switch (choice4) {
				case 1:
					if (wallet.GetBalance() == 0) {
						cout << "\n\n\t\t\t\t\tYou haven`t money! Please top your card!" << endl;
					}
					else {
						wallet.EnterCosts();
					}
					break;
				case 2:
					if (debit->GetAmountOfCard() > 1) {
						cout << "\n\n\t\t\t\t\tYou have " << debit->GetAmountOfCard() << " debit cards. Choose one card: " << endl;
						debit->Print();
						cout << endl;
						do {
							cout << "\n\n\t\t\t\t\t(your answer): ";
							cin >> choice4_1;
							switch (choice4_1)
							{
							case 1:
								debit[0].EnterCosts();
								break;
							case 2:
								debit[1].EnterCosts();
								break;
							case 3:
								debit[2].EnterCosts();
								break;
							default:
								cout << "\n\n\t\t\t\t\tWrong choice!" << endl;
								check4 = false;
								break;
							}
						} while (!check4);
					}
					if (debit->GetAmountOfCard() == 0) {
						cout << "\n\n\t\t\t\t\tYou didn`t create a debit card!" << endl;
					}
					if (debit->GetAmountOfCard() == 1) {
						debit->EnterCosts();
					}
					break;
				case 3:
					if (credit->GetAmountOfCard() > 1) {
						cout << "\n\n\t\t\t\t\tYou have " << debit->GetAmountOfCard() << " credit cards. Choose one card: " << endl;
						credit->Print();
						cout << endl;
						do {
							cout << "\n\n\t\t\t\t\t(your answer): ";
							cin >> choice4_1;
							switch (choice4_1)
							{
							case 1:
								credit[0].EnterCosts();
								break;
							case 2:
								credit[1].EnterCosts();
								break;
							case 3:
								credit[2].EnterCosts();
								break;
							default:
								cout << "\n\n\t\t\t\t\tWrong choice!" << endl;
								check4 = false;
								break;
							}
						} while (!check4);
					}
					if (credit->GetAmountOfCard() == 0) {
						cout << "\n\n\t\t\t\t\tYou didn`t create a credit card!" << endl;
					}
					if (credit->GetAmountOfCard() == 1) {
						credit->EnterCosts();
					}
					break;
				default:
					check2 = false;
					break;
				}
			} while (!check2);
			break;
		case 5:
			system("CLS");
			cout << "\n\t\t\t\t\t[1] - Report about expanses and categories\n\n\t\t\t\t\t[2] - Rating TOP-3 expanses\n\n\t\t\t\t\t[3] - rating TOP-3 categories\n ";
			cout << "\n\n\t\t\t\t\t(your answer): ";
			cin >> choice5;
			if (choice5 == 1) 
			{
				cout << "\n\n\t\t\t\t\t[1] - wallet\n\n\t\t\t\t\t[2] - debit card\n";
				cin >> choice5_1;
				if (choice5_1 == 1) {
					wallet.ReportByCategory();
				}
				else if (choice5_1 == 2) {
					debit->ReportByCategory();
				}
				else {
					cout << "\n\n\t\t\t\t\tError" << endl;
				}
			}
			else if (choice5 == 2) {
				cout << "\n\n\t\t\t\t\t[1] - wallet\n\n\t\t\t\t\t[2] - debit card\n";
				cin >> choice5_1;
				if (choice5_1 == 1) {
					wallet.RatingMax();
				}
				else if (choice5_1 == 2) {
					debit->RatingMax();
				}
				else {
					cout << "\n\n\t\t\t\t\tError" << endl;
				}
			}
			else if (choice5 == 3) {
				cout << "\n\n\t\t\t\t\t[1] - wallet\n\n\t\t\t\t\t[2] - debit card\n";
				cin >> choice5_1;
				if (choice5_1 == 1) {
					wallet.RatingMax();	
				}
				else if (choice5_1 == 2) {
					debit->RatingMax();
				}
				else {
					cout << "\n\n\t\t\t\t\tError" << endl;
				}
			}
			else {
				cout << "\n\n\t\t\t\t\tError!" << endl;
			}
			break;
		case 6:
			system("CLS");
			cout << "\n\n\t\t\t\t\tExiting..." << endl;
			check = true;
			break;
		default:
			cout << "\n\n\t\t\t\t\tTry again!" << endl;
			check = false;
			break;
		}
		int userCheck;
		cout << "\n\n\t\t\t\t\tContinue? [1] - yes\t[0] - no\n";
		cout << "\n\n\t\t\t\t\t(your answer): ";
		cin >> userCheck;
		if (userCheck == 1) {
			check = false;
		}
		else if (userCheck == 0) {
			check = true;
		}
		else {
			cout << "\n\n\t\t\t\t\tIncorrect choice!" << endl;
		}
		system("CLS");
	} while (!check);

	//clearing memory
	delete[] debit;
	delete[] credit;
}

int main()
{
	Wallet wallet;
	Card* debit = new Debit();
	Card* credit = new Credit();
	SelectOperation(debit, credit, wallet);
}