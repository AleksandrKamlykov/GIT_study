#pragma once
#include<iostream>
using namespace std;


class Product
{
private:
	string name;
	string description;
	float price;
	int quantity;
public:
	void setName(string name);
	void setDescription(string description);
	void setPrice(float price);
	void setQuantity(int quantity);
	Product() {
		this->setName("Unnamed");
		this->setDescription("Without description");
		this->setPrice(0);
		this->setQuantity(0);
	}
	Product(string name, string description, float price, int quantity) {
		this->setName(name);
		this->setDescription(description);
		this->setPrice(price);
		this->setQuantity(quantity);
	}
	string getName();
	string getDescription();
	float getPrice();
	float getQuantity();
	void showInfo();
	friend std::ostream& operator<<(std::ostream& os, const Product& product);

	friend std::istream& operator>>(std::istream& is, Product& product);

};