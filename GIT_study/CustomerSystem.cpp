#include "CustomerSystem.h"

void CustomerSystem::createAccount(string name)
{
	Customer newCustomer;
	newCustomer.setName(name);
	this->users.push_back(newCustomer);
}

void CustomerSystem::liginCustomer(string name)
{
	int index = -1;

	for (int i = 0; i < this->users.size(); i++) {
		if (this->users[i].getName() == name) {
			index = i;
			break;
		}
	}
	if (index >= 0) {
		this->loggedCustomers.push_back(*this->getCustomer(name));
	}
	else {
		cout << "ERROR: Customer with name: " << name << " not found" << endl;
	}
}

void CustomerSystem::showAllCustomers()
{
	for (int i = 0; i < this->users.size(); i++) {
		this->users[i].showInfo();
	}
}

Customer* CustomerSystem::getCustomer(string name)
{
	int index = -1;

	for (int i = 0; i < this->users.size(); i++) {
		if (this->users[i].getName() == name) {
			index = i;
			break;
		}
	}

	return &this->users[index];
}

Customer* CustomerSystem::getCustomer(int id)
{
	int index = -1;

	for (int i = 0; i < this->users.size(); i++) {
		if (this->users[i].getId() == id) {
			index = i;
			break;
		}
	}

	return &this->users[index];
}
