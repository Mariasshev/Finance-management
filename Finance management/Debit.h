#pragma once
#include "Card.h"
class Debit:public Card
{
private:
	int amount_of_card;
	double curr_balance;
	int limit;
public:
	//create a debit card
	void EnterData();
	//top up a debit card;
	void TopUp();

	void EnterCosts();
	//return a choosen category
	string ChooseCategory();
	//return amount of cards
	int GetAmountOfCard();
	//show all category for user
	void ShowCategory();
	void Print();
};

