#pragma once
#include "Statuses.h"
#include <string>
#include "Order.h"
#include "Customer.h"
#include <vector>

class OrderSystem {
private:
	vector<Order> orders;
public:
	void addOrder(Cart* cart, Customer& user);
	Order* getOrderByCustomer(string name);
	void showOrderByStatus(Statuses status);
};

