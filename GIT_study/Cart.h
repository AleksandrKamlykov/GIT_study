#pragma once
#include <iostream>
#include <vector>
#include "Product.h"
using namespace std;

class Cart
{
private:
	vector<Product> products;
public:
	void addProduct(Product& product);
	void removeProduct(string name);
	void showProducts();
	int getQuantityProducts();
	float getTotalPrice();
};

