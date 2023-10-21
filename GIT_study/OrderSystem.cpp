#include "OrderSystem.h"
#include "Payment.h"

void OrderSystem::addOrder(Cart* cart, Customer& user)
{

	Order o(*cart, user);

	this->orders.push_back(o);
}

Order* OrderSystem::getOrderByCustomer(string name)
{
	int index = -1;
	for (int i = 0; i < this->orders.size(); i++) {
		if (this->orders[i].getCustomerName() == name) {
			return &orders[i];
		}
		else {
			return nullptr;
		}
	}
}

void OrderSystem::showOrderByStatus(Statuses status)
{

	for (int i = 0; i < this->orders.size(); i++) {
		if (this->orders[i].getStatus() == status) {
			orders[i].getOrderInfo();
		}
	}

}

