#include <iostream>
#include <vector>
#include "Product.h"
#include "Cart.h"
#include "Statuses.h"
#include "Customer.h"
#include "Order.h"
#include <fstream>
#include<string>
#include "CustomerSystem.h"
#include "OrderSystem.h"
using namespace std;




void main() {

	Product iphonex("Iphone XS MAX 4/256", "top smartphone s", 12700, 2);



	Product appleWatch("appleWatch Series 7", "Smart watch designed by Apple", 800, 12);
	Product mxMaster("Logitec MX Master", "The best mouse", 200, 1);


	Cart aleksandrCard;
	aleksandrCard.addProduct(iphonex);


	CustomerSystem userSystem;
	userSystem.createAccount("aleksandr");
	userSystem.createAccount("svitlana");
	userSystem.getCustomer("aleksandr")->addMoney(13000);

	OrderSystem ordersystem;
	aleksandrCard.addProduct(mxMaster);
	ordersystem.addOrder(&aleksandrCard, *userSystem.getCustomer("aleksandr"));

	ordersystem.showOrderByStatus(NEW);
	
	ordersystem.getOrderByCustomer("aleksandr")->pay();
	ordersystem.getOrderByCustomer("aleksandr")->deliver();
	ordersystem.showOrderByStatus(DONE);
	

}