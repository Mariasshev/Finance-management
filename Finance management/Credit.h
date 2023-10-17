#pragma once
#include "Card.h"

class Credit :public Card
{
private:
	int amount_of_card;
	double curr_balance;
	int limit;
public:
	//create a credit card
	void EnterData();
	//top up the credit card
	void TopUp();
	void EnterCosts();
	//return a choosen category
	string ChooseCategory();
	int GetAmountOfCard();
	void ShowCategory();
	void Print();
};
