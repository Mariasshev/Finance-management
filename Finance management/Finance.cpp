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

void Finance::ReportByCategory()
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
				for (size_t i = 0; i < inf.size(); ++i) {
					for (size_t j = 0; j < inf.size(); ++j) {
						if (day == inf[i].day || month == inf[i].month) {
							report = inf[i].category + ": " + to_string(inf[i].costs) + "$\n";
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
				for (size_t i = 0; i < inf.size(); ++i) {
					for (size_t j = 0; j < inf.size(); ++j) {
						if (day == inf[i].day || month == inf[i].month) {
							if (stop == 7) {
								break;
							}
							report = inf[i].category + ": " + to_string(inf[i].costs) + "$\n";
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
				for (size_t i = 0; i < inf.size(); ++i) {
					for (size_t j = 0; j < inf.size(); ++j) {
						if (day == inf[i].day || month == inf[i].month) {
							if (stop == 30) {
								break;
							}
							report = inf[i].category + ": " + to_string(inf[i].costs) + "$\n";
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
				int max = inf[0].costs;
				int index;
				out << "Rating for top-3 expanses in week:" << endl;
				for (size_t i = 0; i < inf.size(); ++i) {
					for (size_t j = 0; j < inf.size(); ++j) {

						if (stop == 7) {
							break;
						}
						else {
							if (inf[i].costs > max)
							{
								max = inf[i].costs;
								index = i;
							}
						}
						stop++;
					}
				}
				report = inf[index].category + ": " + to_string(max) + "$\n";
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
				for (size_t i = 0; i < inf.size(); ++i) {
					for (size_t j = 0; j < inf.size(); ++j) {

						if (stop == 30 || count == 3)
						{
							break;
						}
						else {
							report = inf[i].category + ": " + to_string(inf[i].costs) + "$\n";
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
