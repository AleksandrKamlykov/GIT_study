#pragma once
#include <iostream>
#include "Cart.h"
#include "Statuses.h"
#include "Customer.h"
using namespace std;

class Order
{
private:
	Cart cart;
	Customer user;
	Statuses status = NEW;
public:
	Order(){}
	Order(Cart& cart, Customer& user) {

		this->cart = cart;
		this->user = user;
	}
	string getCustomerName();
	void showProducts();
	Statuses getStatus();
	void getOrderInfo();
	void setStatus(Statuses status);
	float getTotalPrice();
	void pay();
	void deliver();
};

