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
	cout << "\n\t\t\t\t\tWelcome to your finance system!" << endl << endl;
	cout << "\t\t\t\t\t[1] - Fill up a purse\n";
	cout << "\t\t\t\t\t[2] - Top up your card\n";
	cout << "\t\t\t\t\t[3] - Create a card\n";
	cout << "\t\t\t\t\t[4] - Withdraw money\n";
	cout << "\t\t\t\t\t[5] - Financial report\n";
	cout << "\t\t\t\t\t[6] - Exit the program\n";

	cout << "Select operation: ";
}

void SelectOperation() {
	Card* debit = new Debit();
	Card* credit = new Credit();
	Wallet wallet;
	int counter = 1;
	int counter_credit = 1;
	int choice;
	int choice4;
	int choice4_1;
	int choice5;
	int choice5_1;
	int userAsw;
	bool check2 = true;
	bool check = true;
	bool check4 = true;
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
				cout << "Top up: \n[1] - debit card\n [2] - credit card";
				cout << "(your answer): ";
				cin >> choice4;
				switch (choice4) {
				case 1:
					if (debit->GetAmountOfCard() > 1)
					{
						cout << "You have " << debit->GetAmountOfCard() << " debit cards. Choose one card: " << endl;
						debit->Print();
						cout << endl;
						do {
							cout << "(your answer): ";
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
								cout << "Wrong choice!" << endl;
								check4 = false;
								break;
							}
						} while (!check4);
					}
					if (debit->GetAmountOfCard() == 0) {
						cout << "You don`t have a debit card!" << endl;
					}
					if (debit->GetAmountOfCard() == 1) {
						debit->TopUp();
					}
					break;
				case 2:
					if (credit->GetAmountOfCard() > 1)
					{
						cout << "You have " << credit->GetAmountOfCard() << " credit cards. Choose one card: " << endl;
						debit->Print();
						cout << endl;
						do {
							cout << "(your answer): ";
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
								cout << "Wrong choice!" << endl;
								check4 = false;
								break;
							}
						} while (!check4);
					}
					if (credit->GetAmountOfCard() == 0) {
						cout << "You don`t have a credit card!" << endl;
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
			cout << "Which card do you want to create? \n [1] - debit card\n [2] - credit card\n";
			check2 = true;
			do {
				cin >> userAsw;
				switch (userAsw)
				{
				case 1:
					if (debit->GetAmountOfCard() > 3) {
						cout << "Exceeding the limit of debit cards!" << endl;
					}
					else {
						debit->EnterData();
						debit->Print();
					}
					break;
				case 2:
					if (credit->GetAmountOfCard() > 3) {
						cout << "Exceeding the limit of credit cards!" << endl;
					}
					else {
						credit->EnterData();
						credit->Print();
					}
					break;
				default:
					cout << "Incorrect choice" << endl;
					check2 = false;
					break;
				}
			} while (!check2);
			break;
		case 4:
			system("CLS");
			do {
				cout << "Withdraw money from: \n [1] - wallet \n [2] - debit card\n [3] - credit card";
				cout << "(your answer): ";
				cin >> choice4;
				switch (choice4) {
				case 1:
					if (wallet.GetBalance() == 0) {
						cout << "You haven`t money! Please top your card!" << endl;
					}
					else {
						wallet.EnterCosts();
					}
					break;
				case 2:
					if (debit->GetAmountOfCard() > 1) {
						cout << "You have " << debit->GetAmountOfCard() << " debit cards. Choose one card: " << endl;
						debit->Print();
						cout << endl;
						do {
							cout << "(your answer): ";
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
								cout << "Wrong choice!" << endl;
								check4 = false;
								break;
							}
						} while (!check4);
					}
					if (debit->GetAmountOfCard() == 0) {
						cout << "You didn`t create a debit card!" << endl;
					}
					if (debit->GetAmountOfCard() == 1) {
						debit->EnterCosts();
					}
					break;
				case 3:
					if (credit->GetAmountOfCard() > 1) {
						cout << "You have " << debit->GetAmountOfCard() << " credit cards. Choose one card: " << endl;
						credit->Print();
						cout << endl;
						do {
							cout << "(your answer): ";
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
								cout << "Wrong choice!" << endl;
								check4 = false;
								break;
							}
						} while (!check4);
					}
					if (credit->GetAmountOfCard() == 0) {
						cout << "You didn`t create a credit card!" << endl;
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
			cout << "[1] - Report about expanses and categories\n[2] - Rating TOP-3 expanses\n[3] - rating TOP-3 categories\n ";
			cout << "(your answer): ";
			cin >> choice5;
			if (choice5 == 1) 
			{
				cout << "[1] - wallet\n[2] - debit card\n";
				cin >> choice5_1;
				if (choice5_1 == 1) {
					wallet.WriteReportToFile();
				}
				else if (choice5_1 == 2) {
					debit->WriteReportToFile();
				}
				else {
					cout << "Error" << endl;
				}
			}
			else if (choice5 == 2) {
				cout << "[1] - wallet\n[2] - debit card\n";
				cin >> choice5_1;
				if (choice5_1 == 1) {
					wallet.RatingMax();
				}
				else if (choice5_1 == 2) {
					debit->RatingMax();
				}
				else {
					cout << "Error" << endl;
				}
			}
			else if (choice5 == 3) {
				cout << "[1] - wallet\n[2] - debit card\n";
				cin >> choice5_1;
				if (choice5_1 == 1) {
					//wallet.RatingMax();	доделать
				}
				else if (choice5_1 == 2) {
					//debit->RatingMax();	доделать
				}
				else {
					cout << "Error" << endl;
				}
			}
			else {
				cout << "Error!" << endl;
			}
			break;
		case 6:
			system("CLS");
			cout << "Exiting..." << endl;
			check = true;
			break;
		default:
			cout << "Try again" << endl;
			check = false;
			break;
		}
		int userCheck;
		cout << "Continue? [1] - yes\t[0] - no\n";
		cin >> userCheck;
		if (userCheck == 1) {
			check = false;
		}
		else if (userCheck == 0) {
			check = true;
		}
		else {
			cout << "Incorrect choice" << endl;
		}
		system("CLS");
	} while (!check);

	delete[] debit;
	delete[] credit;
}

int main()
{
	SelectOperation();
}