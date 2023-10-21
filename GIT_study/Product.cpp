#include "Product.h"

void Product::setName(string name)
{
	if (size(name) > 0) {
		this->name = name;
	}
	else {
		this->name = "Unnamed";
	}
}

void Product::setDescription(string description)
{
	if (size(description) > 0) {
		this->description = description;
	}
	else {
		this->description = "Without description";
	}
}

void Product::setPrice(float price)
{
	if (price > 0) {
		this->price = price;
	}
	else {
		this->price = 0;
	}
}

void Product::setQuantity(int quantity)
{
	if (quantity > 0) {
		this->quantity = quantity;
	}
	else {
		this->quantity = 0;
	}
}

string Product::getName()
{
	return this->name;
}

string Product::getDescription()
{
	return this->description;
}

float Product::getPrice()
{
	return this->price;
}

float Product::getQuantity()
{
	return this->quantity;
}

void Product::showInfo()
{
	cout << "Product name: " << this->getName() << "\nDescription: " << this->getDescription() << "\nPrice: " << this->getPrice() << "\n-----------------" << endl;
}

std::ostream& operator<<(std::ostream& os, const Product& product)
{
	os << product.name << " " << product.description << " " << product.price << " " << product.quantity;
	return os;
}

std::istream& operator>>(std::istream& is, Product& product)
{
	is >> product.name >> product.description >> product.price >> product.quantity;

	return is;
}
