#include "Finance.h"
#include <iostream>
#include <fstream>

using namespace std;

void Finance::Print()
{
}

double Finance::GetBalance()
{
	return curr_balance;
}

void Finance::WriteReportToFile()
{
	{
		string fileName = "expenses.txt";
		ofstream out(fileName);
		string report;
		int choose;
		int day, month;

		cout << "[1] - day\t[2] - week\t[3] - month?" << endl;
		cout << "(your answer): ";
		cin >> choose;
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		switch (choose)
		{
		case 1:
			if (out.is_open())
			{
				out << "Report for " << day << "/" << month << "\t" << endl;
				for (size_t i = 0; i < arr.size(); ++i) {
					for (size_t j = 0; j < arr.size(); ++j) {
						if (day == arr[i].day || month == arr[i].month) {
							//cout << "Category: " << arr[i].category << "\tCosts: " << arr[i].costs << "\tDate: " << arr[i].day << "/" << arr[i].month << "\tType: " << arr[i].type << endl;
							//i++;

							report = arr[i].category + ": " + to_string(arr[i].costs) + "$\n";
							out << report;
							i++;
						}

					}
				}
				out.close();
				cout << "Information is written in " << fileName << endl;
			}
			else
			{
				cout << "Cannot open file " << fileName << endl;
			}
			break;
		case 2:
			if (out.is_open())
			{
				int stop = 0;
				out << "Report for " << day << "/" << month << " to " << day + 7 << "/" << month << endl;
				for (size_t i = 0; i < arr.size(); ++i) {
					for (size_t j = 0; j < arr.size(); ++j) {
						if (day == arr[i].day || month == arr[i].month) {
							if (stop == 7) {
								break;
							}
							report = arr[i].category + ": " + to_string(arr[i].costs) + "$\n";
							out << report;
							i++;
							stop++;
						}

					}
				}
				out.close();
				cout << "Information is written in " << fileName << endl;
			}
			else
			{
				cout << "Cannot open file " << fileName << endl;
			}
			break;
		case 3:
			if (out.is_open())
			{
				int stop = 0;
				out << "Report for " << day << "/" << month << " to " << day + 7 << "/" << month << endl;
				for (size_t i = 0; i < arr.size(); ++i) {
					for (size_t j = 0; j < arr.size(); ++j) {
						if (day == arr[i].day || month == arr[i].month) {
							if (stop == 30) {
								break;
							}
							report = arr[i].category + ": " + to_string(arr[i].costs) + "$\n";
							out << report;
							i++;
							stop++;
						}

					}
				}
				out.close();
				cout << "Information is written in " << fileName << endl;
			}
			else
			{
				cout << "Cannot open file " << fileName << endl;
			}
			break;
		default:
			cout << "Wrong choice" << endl;
			break;
		}
	}
}

void Finance::RatingMax()
{
	{
		string fileName = "expenses.txt";
		ofstream out(fileName);
		string report;
		int choose;

		cout << "[1] - week\t[2] - month?" << endl;
		cout << "(your answer): ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (out.is_open())
			{
				int stop = 0;
				int max = arr[0].costs;
				int index;
				out << "Rating for top-3 expanses in week:" << endl;
				for (size_t i = 0; i < arr.size(); ++i) {
					for (size_t j = 0; j < arr.size(); ++j) {

						if (stop == 7) {
							break;
						}
						else {
							if (arr[i].costs > max)
							{
								max = arr[i].costs;
								index = i;
							}
						}
						stop++;
					}
				}
				report = arr[index].category + ": " + to_string(max) + "$\n";
				out << report;

				out.close();
				cout << "Information is written in " << fileName << endl;
			}
			else
			{
				cout << "Cannot open file " << fileName << endl;
			}
			break;
		case 2:
			if (out.is_open())
			{
				int stop = 0;
				int count = 0;

				out << "Rating for top-3 expanses in month:" << endl;
				for (size_t i = 0; i < arr.size(); ++i) {
					for (size_t j = 0; j < arr.size(); ++j) {

						if (stop == 30 || count == 3)
						{
							break;
						}
						else {
							report = arr[i].category + ": " + to_string(arr[i].costs) + "$\n";
							out << report;
							count++;
						}
						stop++;
					}
				}
				out.close();
				cout << "Information is written in " << fileName << endl;
			}
			else
			{
				cout << "Cannot open file " << fileName << endl;
			}
			break;
		default:
			cout << "Wrong choice" << endl;
			break;
		}
	}
}
