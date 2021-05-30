#ifndef _MANAGER_H
#define _MANAGER_H

#include "address.h"
#include "buyer.h"
#include "seller.h"
#include "helper.h"
#include "product.h"
#include "order.h"
#include "user.h"
#include "combined.h"



class Manager
{
private:
	string name; // check syntax
	
	vector<Order*> orderArray;
	vector<User*> userArray;
public:
	Manager(const string& name);
	Manager(const Manager& other);
	Manager(Manager && other);
	~Manager();
	
	const string& getName()             const;
	bool setName(const string& name);
	void addUser(User* user);

	void addOrder(Order* buyer);
	bool checkName(const string& name);
	Order* checkIfOrderExists(const string& name) ;
	bool findBuyerPurchases(const string& name);
	
	unsigned int get_Physical_Number_Of_Users() const;
	unsigned int get_Logical_Number_Of_Users() const;

	unsigned int get_Logical_Number_Of_Orders() const;
	unsigned int get_Physical_Number_Of_Orders() const;

	vector<User*> getUserArray()     const;

	vector<Order*>  getOrderArray()        const;

	
	void showProductsDetails(const string& productName) const;
	void showDetails(const type_info &type, const type_info &type2) const;

	
	const Manager& operator+=(User* user)
	{
		this->addUser(user);
		return *this;
	}
	
	Buyer* checkIfBuyer(const string& name);
	void printSellerProduct(Seller* seller);

	User* findSellerPlace(const string& name);

	void addItemToSeller(Product* product, User* user);
	void checkOperatorGadol();

	void saveUsers(const string& filename);
	void loadUsers(const string& filename);

};
#endif // _MANAGER_H
