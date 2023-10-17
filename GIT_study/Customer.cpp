#include "Customer.h"

void Customer::setDescription(string desc)
{
	this->description = desc;
}

void Customer::setName(string name)
{
	this->name = name;
}

string Customer::getName()
{
	return this->name;
}

int Customer::getId()
{
	return this->id;
}

void Customer::showInfo()
{
	cout << "User name: " << this->getName() << "\nID: " << this->getId() << "\n----------------" << endl;
}

void Customer::addMoney(float sum)
{
	this->money += sum;
}

float Customer::getMoney()
{
	return this->money;
}

void Customer::spendMoney(float sum)
{
	this->money -= sum;
}
int Customer::userID = 0;