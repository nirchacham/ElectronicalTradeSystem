#ifndef _BUYER_H
#define _BUYER_H
#include "helper.h"
#include "cart.h"
#include "user.h"


class Buyer : virtual public User
{
protected:
	
	Cart cart;
	
public:	
	Buyer() = default;
	Buyer(const string& name, const string& password, const Address& address, Cart& cart) : User(name, password, address), cart(cart) {}
	Buyer(const string& name, const string& password, const Address& address) : User(name, password, address) {}
	Buyer(ifstream& inFile) :User(inFile) {}
	Buyer(const Buyer& other) :User(other) , cart(other.cart) {	}
	Buyer(Buyer&& other) : User(other), cart(other.cart) {}
	~Buyer() {}

	bool operator>(const Buyer& other)
	{
		if (this->cart.getTotalPrice() > other.cart.getTotalPrice()) {
			return true;
		}
		return false;
	}
	
	Cart& getCart();
	
	friend class Manager;
};

#endif // _BUYER_H

