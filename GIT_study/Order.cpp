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

void Order::pay()
{

	bool customerCanPay = this->getTotalPrice() < this->user.getMoney();

	if (customerCanPay) {
		this->user.spendMoney(this->getTotalPrice());
		this->setStatus(DONE);
	}
	else {
		cout << "Error: " << this->user.getName() << " does not enough money!" << endl;
	}
}

void Order::deliver()
{
	if (this->getStatus() == DONE) {
		cout << "Order: " << this->user.getName() << endl;
		this->showProducts();
		cout << "Will be deliver in next work day" << endl;
	}
	else {
		cout << "ERRor: this order can not be deliver" << endl;
	}
}
