#pragma once
#include <string>
#include <vector>
#include "Customer.h"
#include "Statuses.h"

class CustomerSystem
{
private:
	vector<Customer> users;
	vector<Customer> loggedCustomers;
public:
	void createAccount(string name);
	void liginCustomer(string name);
	void showAllCustomers();
	Customer* getCustomer(string name);
	Customer* getCustomer(int id);


};

