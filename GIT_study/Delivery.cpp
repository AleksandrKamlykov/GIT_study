#include "Delivery.h"

void Delivery::deliver(Order& order, Customer& customer)
{
	cout << "Order: " << customer.getName() << endl;
	order.showProducts();
	cout << "Will be deliver in next work day" << endl;
}
