#include <iostream>
#include <vector>
#include "Product.h"
#include "Cart.h"
#include "Statuses.h"
#include "Customer.h"
#include "Order.h"
#include <fstream>
#include<string>
using namespace std;


class CustomerSystem {
private:
	vector<Customer> users;
	vector<Customer> loggedCustomers;
public:
	void createAccount(string name) {
		Customer newCustomer;
		newCustomer.setName(name);
		this->users.push_back(newCustomer);
	}
	void liginCustomer(string name) {
		int index = -1;

		for (int i = 0; i < this->users.size(); i++) {
			if (this->users[i].getName() == name) {
				index = i;
				break;
			}
		}
		if (index >= 0) {
			this->loggedCustomers.push_back(*this->getCustomer(name));
		}
		else {
			cout << "ERROR: Customer with name: " << name << " not found" << endl;
		}
	}
	void showAllCustomers() {
		for (int i = 0; i < this->users.size(); i++) {
			this->users[i].showInfo();
		}
	}
	Customer* getCustomer(string name) {
		int index = -1;

		for (int i = 0; i < this->users.size(); i++) {
			if (this->users[i].getName() == name) {
				index = i;
				break;
			}
		}

		return &this->users[index];
	}
	Customer* getCustomer(int id) {
		int index = -1;

		for (int i = 0; i < this->users.size(); i++) {
			if (this->users[i].getId() == id) {
				index = i;
				break;
			}
		}

		return &this->users[index];
	}
	

};

class OrderSystem {
private:
	vector<Order> orders;
public:
	void addOrder(Cart* cart, Customer& user) {

		Order o(*cart, user);

		this->orders.push_back(o);
	}
	Order* getOrderByCustomer(string name) {
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
	void showOrderByStatus(Statuses status) {

		for (int i = 0; i < this->orders.size(); i++) {
			if (this->orders[i].getStatus() == status) {
				orders[i].getOrderInfo();
			}
		}

	}
};

class File {
private:
	ofstream fout;
	ifstream fin;
	string path;
public:
	File(string path) {
		this->path = path;
	}
	void appendToFile(string str) {
		this->fout.open(this->path, ofstream::app);

		if (!this->fout.is_open()) {
			cout << "ERR open file" << endl;
		}
		else {
			this->fout << "test_data\n";
		}

		this->fout.close();
	}
	void readFile() {

		this->fin.open(this->path);

		if (!this->fin.is_open()) {
			cout << "ERR open read file" << endl;
		}
		else {

			vector<string>lines;
			string str;

			while (!this->fin.eof()) {
				getline(this->fin, str);

			}
		}

		this->fin.close();
	}
};

template<class T>
class FileManager {
private:
	ofstream fout;
	ifstream fin;
	string path;
public:
	FileManager(string path) {
		this->path = path;
	}
	void appendToFile(T obj) {
		this->fout.open(this->path, ofstream::app);

		if (!this->fout.is_open()) {
			cout << "ERR open file" << endl;
		}
		else {
			
			this->fout.write((char*)&obj, sizeof(T));


		}

		this->fout.close();
	}
	void readFile() {

		this->fin.open(this->path);

		if (!this->fin.is_open()) {
			cout << "ERR open read file" << endl;
		}
		else {

			T prod;
			this->fin.read((char*)&prod, sizeof(T));

			prod.showInfo();
	
		}

		this->fin.close();
	}
};

void main() {

	Product iphone("Iphone XS Max", "This is top smartphone", 700, 2);
	FileManager<Product> productFile("product3.txt");
	FileManager<Customer> customerFile("custom.txt");

	//Customer custom;
	//custom.setName("Aleksandr");
	//custom.setDescription("Human");
	//customerFile.appendToFile(custom);
	//customerFile.readFile();

	//productFile.appendToFile(iphone);
	productFile.readFile();
	//Product appleWatch("appleWatch Series 7", "Smart watch designed by Apple", 800, 12);
	//Product mxMaster("Logitec MX Master", "The best mouse", 200, 1);


	//Cart aleksandrCard;
	//aleksandrCard.addProduct(iphone);


	//CustomerSystem userSystem;
	//userSystem.createAccount("Aleksandr");
	//userSystem.createAccount("Svitlana");

	//OrderSystem orderSystem;
	//aleksandrCard.addProduct(mxMaster);
	//orderSystem.addOrder(&aleksandrCard, *userSystem.getCustomer("Aleksandr"));

	//orderSystem.showOrderByStatus(NEW);
	//
	//orderSystem.getOrderByCustomer("Aleksandr")->setStatus(DONE);
	//orderSystem.showOrderByStatus(DONE);
	

}