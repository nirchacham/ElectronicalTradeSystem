#include "product.h"

Product::Product()
{
	serialNumber = ++counter;
}

Product::Product(const eCategoryType category, const string& name, const float price)
{
	this->category = category;
	this->name = name;
	this->price = price;
	serialNumber = ++counter;
}

Product::Product(const Product & other)  // copy cons
{
	this->category = other.category;
	this->name = other.name;
	this->serialNumber = other.serialNumber;
	this->counter = other.counter;
}

Product::Product(Product && other)
{
	this->category = other.category;
	this->name = other.name;
	other.name = nullptr;
	this->serialNumber = other.serialNumber;
	this->counter = other.counter;
}

//------------------------------------

const string& Product:: getName()  const
{
	return name;
}

Product::eCategoryType Product::getCategory()   const  
{
	return category;

}

float Product::getPrice()    const
{
	return price;
}

unsigned int Product::getSerialNumber() const
{
	return serialNumber;
}

Seller * Product::getSeller() const
{
	return productSeller;
}

bool Product::setName(const string& name)
{
	this->name = name;
	return true;
}

bool Product::setCategory(eCategoryType category)
{
	if (category < 0 || category>3) {
		return false;
	}
	this->category = category;
	return true;
}

bool Product::setPrice(float price)
{
	if (price < 0)
	{
		cout << "The number isnt valid " << endl;
		return false;
	}

	this->price = price;
	return true;
}

void Product::setSeller( Seller* other)
{
	this->productSeller = other;
}

int Product::counter = 0;

