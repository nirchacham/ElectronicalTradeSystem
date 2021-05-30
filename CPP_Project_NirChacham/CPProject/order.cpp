#include "order.h"

Order::Order()
{
	totalPrice = 0;
	vector<Product*> buyerOrder; 
	this->paid = false;
}

Order::Order(const Order & other)
{
	this->totalPrice = other.totalPrice;
	this->buyer = other.buyer;
	paid = other.paid;

	vector<Product*>::iterator itr = buyerOrder.begin();
	vector<Product*>::const_iterator itrother = other.buyerOrder.begin();
	vector<Product*>::const_iterator itrendother = other.buyerOrder.end();
	for (; itrother != itrendother; ++itr, ++itrother)
		(*itr) = (*itrother);
}

Order::Order(Order && other)
{
	this->totalPrice = other.totalPrice;
	this->buyerOrder = other.buyerOrder;
	this->buyer = other.buyer;
	other.buyer = nullptr;	
	paid = other.paid;
}

Order::~Order()
{
}

float Order::getPrice() const
{
	return totalPrice;
}

bool Order::getStatus() const
{
	return paid;
}

//func that returns the products that are in the order
vector<Product*> Order::getBuyerOrder()
{
	return buyerOrder;
}

//func that returns pointer to the buyer that made the order
Buyer * Order::getBuyer()
{
	return buyer;
}

void Order::setPrice(float price)
{
	this->totalPrice += price;
}

void Order::setBuyer(Buyer * buyer)
{
	this->buyer = buyer;
}
//func that sets the status if the buyer paid for the order or not
void Order::setStatus(int choice)
{
	if (choice == 1)
		this->paid = true;
	else
		this->paid = false;
}

//func that adds the products to the products array
void Order::addProduct(Product* product)
{
		if (buyerOrder.size() == buyerOrder.capacity())
		{
			buyerOrder.reserve(buyerOrder.capacity() * 2);
		}
		buyerOrder.push_back(product);
}

unsigned int Order::get_Physical_Number_Of_Products() const
{
	return buyerOrder.capacity();
}

unsigned int Order::get_Logical_Number_Of_Products() const
{
	return buyerOrder.size();
}
//func that prints the products in the order and the total price
void Order::printOrder() const
{
	cout << "The order contains:\n";
	vector<Product*>::const_iterator itr = buyerOrder.begin();
	vector<Product*>::const_iterator itrEnd = buyerOrder.end();
	int i = 0;
	for (; itr != itrEnd; ++itr)
	{
		//	cout << "product number" << i + 1 << " is\n";
		cout << **itr;
		cout << endl;
		i++;
	}
}

