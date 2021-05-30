#ifndef _SELLER_H
#define _SELLER_H
#include "helper.h"
#include "feedback.h"
#include "user.h"
#include "array.h"

class Product;

class Seller : virtual public User
{
	
protected:
	
	vector<Product *> productArray;
	Array<Feedback*> feedbackArray;

public:
	Seller() ;
	Seller(const string& name, const string& password, const Address& address);
	Seller(ifstream& inFile) :User(inFile) {}
	Seller(const Seller& other);
	Seller(Seller&& other);
	~Seller();

	const Seller& operator=(const Seller& other)
	{
		if (this != &other)
		{

		}

	}

	vector<Product*> getAllProducts()   ; 
	unsigned int get_Physical_Number_Of_Products() const;
	unsigned int get_Logical_Number_Of_Products() const;
	int get_Physical_Number_Of_Feedbacks() ;
	int get_Logical_Number_Of_Feedbacks() ;
	Array<Feedback *> getFeeadbackArray();

	void freeFeedbackArray();

	void addProduct(Product* product);
	
	void addFeedback(Feedback* feedback);

	Product* getSpecificProduct(int serialNumber);

	friend class Manager;
}; 
#endif // _SELLER_H