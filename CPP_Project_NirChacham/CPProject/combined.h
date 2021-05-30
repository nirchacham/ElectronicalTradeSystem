#ifndef _COMBINED_H
#define _COMBINED_H
#include "helper.h"
#include "buyer.h"
#include "seller.h"

class Combined : public Buyer , public Seller
{

public:
	Combined() = default;
	Combined(const Buyer& b, const Seller& s) : User(b),Seller(s), Buyer(b){}
	Combined(ifstream& inFile) :User(inFile),Buyer(),Seller() {}
	Combined(const Combined& other) :User(other), Buyer(other), Seller(other) {}
	Combined(Combined&& other) : User(other), Buyer(other), Seller(other) {}
	~Combined()
	{
		cout << "you erased a combined\n";
	}

	friend class Manager;
};

#endif // _COMBINED_H

