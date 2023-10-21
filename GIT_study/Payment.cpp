#include "Payment.h"

void Payment::transaction(Customer& customer, Order& order)
{
	bool customerCanPay = order.getTotalPrice() < customer.getMoney();
	
	if (customerCanPay) {
		customer.spendMoney(order.getTotalPrice());
		order.setStatus(DONE);
	}
	else {
		cout << "Error: " << customer.getName() << " does not enough money!" << endl;
	}


}
