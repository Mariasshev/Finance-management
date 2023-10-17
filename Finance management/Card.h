#pragma once
#include "Finance.h"

class Card :public Finance
{
protected:
	string fio;
	int phone;
	int* pin;
	string* paymentSystem;
	static int amount_of_card;
	int limit;
public:
	Card();
	void EnterData();
	void TopUp();	
	void EnterCosts();
	void Print();
	void SetPayment(string* p);
	int GetAmountOfCard();
	~Card();
};

