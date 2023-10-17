#pragma once
#include "Finance.h"

class Card :public Finance
{
protected:
	string FIO;
	int phoneNumber;
	int* pin;
	string* paymentSystem;
	static int amount_of_card;
	int limit;
public:
	Card();
	virtual void EnterData();
	virtual void TopUp();	
	virtual void EnterCosts();
	virtual void Print();
	//set a paymentSystem
	void SetPayment(string* p);


	//getters
	string* GetPayment();
	int GetAmountOfCard();
	~Card();
};

