#include "cart.h"

Cart::Cart()
{
	vector<Product*> productArray;
	totalPrice = 0;
}

Cart::Cart(const Cart& other)
{
	vector<Product*>::iterator itr = productsArray.begin();
	vector<Product*>::const_iterator itrother = other.productsArray.begin();
	vector<Product*>::const_iterator itrendother = other.productsArray.end();
	for (; itrother != itrendother; ++itr, ++itrother)
		(*itr) = (*itrother);
}

Cart::Cart(Cart&& other)
{
	this->productsArray = other.productsArray;
	other.productsArray.clear();
	totalPrice = other.totalPrice;
}

Cart::~Cart()
{
}
//func that prints the products
void Cart::showProducts()
{
	vector<Product*>::iterator itr = productsArray.begin();
	vector<Product*>::iterator itrEnd = productsArray.end();
	int i = 0;
	for (; itr != itrEnd; ++itr)
	{
		cout << "product number" << i + 1 << " is\n";
		cout << **itr;
		cout << endl;
		i++;
	}
}
//func that adds products to the product array
void Cart::addProduct(Product* product)
{
	if (productsArray.size() == productsArray.capacity())
	{
		productsArray.reserve(productsArray.capacity() * 2);
	}
	productsArray.push_back(product);
}

unsigned int Cart::get_Physical_Num_Of_Products_In_Cart() const
{
	return productsArray.capacity();
}

unsigned int Cart::get_Logical_Num_Of_Products_In_Cart() const
{
	return productsArray.size();
}
//func that returns the products array that is saved in the cart
vector<Product *> Cart::getproductsArray() 
{
	return productsArray;
}
//func that releases the product array
void Cart::freeCart()
{
	productsArray.clear();
}

//func that sets the product array
void Cart::setProductsArray(vector<Product *> productArray)
{
	this->productsArray = productArray;
}


float Cart::getTotalPrice() const
{
	return totalPrice;
}

void Cart::updateTotalPrice(float price)
{
	totalPrice += price;
}

Product * Cart::getSpecificProduct(int serialNumber)
{
	vector<Product*> temp = productsArray;
	vector<Product*>::iterator itr = temp.begin();
	vector<Product*>::iterator itrEnd = temp.end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getSerialNumber() == serialNumber)
		{
			return (*itr);
		}
	}
	return nullptr;
}


