#pragma once
#include "Card.h"
class Credit :public Card
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
	int GetAmountOfCard() {
		return amount_of_card;
	}
	void ShowCategory();
};
