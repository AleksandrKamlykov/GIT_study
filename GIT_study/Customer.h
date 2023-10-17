#pragma once
#include <iostream>
using namespace std;

class Customer
{
private:
	string name;
	string description;
	static int userID;
	int id;
	float money;
public:
	void setDescription(string desc);
	void setName(string name);
	string getName();
	int getId();
	Customer() {
		this->id = this->userID + 1;
		this->money = 0;
	}
	void showInfo();
	void addMoney(float sum);
	float getMoney();
	void spendMoney(float sum);
};


