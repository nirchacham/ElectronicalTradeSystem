#ifndef _PRODUCT_H
#define _PRODUCT_H

#include "helper.h"

class Seller;

class Product
{
public:
	
	enum eCategoryType{ CHILDREN, ELECTICITY, OFFICE, CLOTHING };
	const string Type[4] = { "Children", "Electricity", "Office", "Clothing" };

	Product();
	Product(const eCategoryType category, const string& name,const float price);
	Product(const Product& other); // copy cons
	Product(Product&& other); 
	

	friend ostream& operator<<(ostream& os, const Product& product)
	{
		os << "Name: " << product.getName() << endl << "Price: " << product.getPrice() << endl <<
		"Category: " << product.Type[product.getCategory()] << endl << "Serialnumber: " << product.getSerialNumber() << endl;
		cout << "*--------------------------------------------------------------------------*\n";
		return os;
	}

	
	const string& getName()                   const;
	eCategoryType getCategory()       const;
	float getPrice()                  const;
	unsigned int getSerialNumber()    const;
	Seller* getSeller()    const;

	bool setName(const string& name);
	bool setCategory(eCategoryType category);
	bool setPrice(float price);
	void setSeller( Seller* other);

	
private:
	Seller* productSeller;
	string name;
	float price;
	eCategoryType category;
	static int counter ;
	unsigned int serialNumber;  
};

#endif // _PRODUCT_H
