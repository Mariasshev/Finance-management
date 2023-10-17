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
	Card() 
	{
		paymentSystem = new string[3];
		pin = new int[3];
	}
	virtual void EnterData();
	virtual void TopUp();	
	virtual void EnterCosts();
	virtual void Print();
	virtual void SetPayment(string* p);
	int GetAmountOfCard() {
		return amount_of_card;
	}
	virtual ~Card(){
		delete[] paymentSystem;
		delete[] pin;
	}
};

