#include "seller.h"

//--------------------------------------------------------------------------------//
Seller::Seller(){}

Seller::Seller(const string& name, const string& password, const Address& address) : User(name, password, address){}

Seller::Seller(const Seller& other) : User(other),feedbackArray(other.feedbackArray)
{
	vector<Product*>::iterator itr = productArray.begin();
	vector<Product*>::const_iterator itrother = other.productArray.begin();
	vector<Product*>::const_iterator itrendother = other.productArray.end();
	for (; itrother != itrendother; ++itr, ++itrother)
		(*itr) = (*itrother);
}

Seller::Seller(Seller && other) : User(other) , feedbackArray(other.feedbackArray)
{
	this->productArray = other.productArray;
}

Seller::~Seller()
{
	for (unsigned int i = 0; i < this->get_Logical_Number_Of_Feedbacks(); i++)  
	{
		delete this->feedbackArray[i];
	}
} 


unsigned int Seller::get_Physical_Number_Of_Products() const
{
	return productArray.capacity();
}

unsigned int Seller::get_Logical_Number_Of_Products() const
{
	return productArray.size();
}

int Seller::get_Physical_Number_Of_Feedbacks() 
{
	return feedbackArray.getCapacitySize();
}

int Seller::get_Logical_Number_Of_Feedbacks() 
{
	return feedbackArray.getSize();
}

Array<Feedback *> Seller::getFeeadbackArray()
{
	return this->feedbackArray;
}

vector<Product *> Seller::getAllProducts() 
{
	return productArray;
}

//func that frees the feedback array
void Seller::freeFeedbackArray()
{
}


//func that adds feedbacks to the feedback array
void Seller::addFeedback(Feedback * feedback)
{
	feedbackArray += feedback;
}
//func that adds products to the products array of the seller
void Seller::addProduct(Product* product)
{
	if (productArray.size() == productArray.capacity())
	{
		productArray.reserve(productArray.capacity() * 2);
	}
	
	productArray.push_back(product);
}


Product * Seller::getSpecificProduct(int serialNumber)
{
	vector<Product*> temp = this->getAllProducts();
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



