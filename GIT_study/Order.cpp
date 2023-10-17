#include "Order.h"

string Order::getCustomerName()
{
	return this->user.getName();
}

void Order::showProducts()
{
	cart.showProducts();
}

Statuses Order::getStatus()
{
	return this->status;
}

void Order::getOrderInfo()
{
	cout << "Order by user: " << this->getCustomerName() << endl;
	this->showProducts();
}

void Order::setStatus(Statuses status)
{
	this->status = status;
}

float Order::getTotalPrice()
{
	return this->cart.getTotalPrice();
}
