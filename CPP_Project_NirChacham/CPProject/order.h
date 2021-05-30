
#ifndef _ORDER_H
#define _ORDER_H
#include "cart.h"
#include "buyer.h"
#include "helper.h"


class Order
{
public:

	Order();
	Order(const Order& other);
	Order(Order&& other);
	~Order();


	float getPrice()       const;
	bool getStatus()     const;
	vector<Product*> getBuyerOrder();
	Buyer* getBuyer();

	void setPrice(float price);
	void setBuyer(Buyer* buyer);
	void setStatus(int choice);
	void addProduct(Product* product);
	unsigned int get_Physical_Number_Of_Products() const;
	unsigned int get_Logical_Number_Of_Products() const;
	void printOrder() const;

private:
	bool paid;
	vector<Product*> buyerOrder;
	float totalPrice;
	Buyer* buyer;
};

#endif // _ORDER_H

