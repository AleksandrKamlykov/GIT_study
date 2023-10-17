#include "Cart.h"

void Cart::addProduct(Product& product)
{
	this->products.push_back(product);
}

void Cart::removeProduct(string name)
{

	int indexForRemove = -1;

	for (int i = 0; i < this->products.size(); i++) {
		if (this->products[i].getName() == name) {
			indexForRemove = i;
			break;
		}
	}
	this->products.erase(this->products.begin() + indexForRemove);
}

void Cart::showProducts()
{
	for (int i = 0; i < this->products.size(); i++) {
		this->products[i].showInfo();
	}
	cout << "|||||||||||||||||||||||||||" << endl;
}

int Cart::getQuantityProducts()
{
	return this->products.size();
}

float Cart::getTotalPrice()
{
	float sum=0;
	for (int i = 0; i < this->getQuantityProducts(); i++) {
	sum +=	this->products[i].getPrice();
	}
	return sum;
}
