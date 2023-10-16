#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Category {
private:
    string name;
    vector<double> expenses;
public:
    Category(const string& categoryName) : name(categoryName) {}
    Category() = default;
    void AddExpense(double expense) 
    {
        expenses.push_back(expense);
    }

    /*double GetTotalExpenses() const {
        double total = 0.0;
        for (double expense : expenses) {
            total += expense;
        }
        return total;
    }*/

    /*const std::string& GetName() const {
        return name;
    }*/
};