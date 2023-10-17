#pragma once
#include "Card.h"
class Debit:public Card
{
private:
	int amount_of_card;
	double curr_balance;
	int limit;
public:
	void EnterData();
	void Print();
	void TopUp();
	void EnterCosts();
	string ChooseCategory();
	int GetAmountOfCard();
	void ShowCategory();
};

