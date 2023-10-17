#include "Card.h"

Card::Card()
{
	paymentSystem = new string[3];
	pin = new int[3];
}

void Card::EnterData() {

}

void Card::TopUp()
{
}

void Card::EnterCosts()
{
}

void Card::Print()
{
}

void Card::SetPayment(string* p)
{
	paymentSystem = p;
}


string* Card::GetPayment()
{
	return paymentSystem;
}

int Card::GetAmountOfCard()
{
	return amount_of_card;
}

Card::~Card()
{
	delete[] paymentSystem;
	delete[] pin;
}
