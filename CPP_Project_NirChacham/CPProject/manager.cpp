#include "manager.h"

Manager::Manager(const string&name)
{
	setName(name);
	vector<User*>  userArray;
	vector<Order*> orderArray;
}

Manager::Manager(const Manager& other)
{
	this->name = other.name;
	vector<User*>::iterator itr = userArray.begin();
	vector<User*>::const_iterator itrother = other.userArray.begin();
	vector<User*>::const_iterator itrendother = other.userArray.end();
	for (; itrother != itrendother; ++itr, ++itrother)
		(*itr) = (*itrother);

	vector<Order*>::iterator itr1 = orderArray.begin();
	vector<Order*>::const_iterator itrother1 = other.orderArray.begin();
	vector<Order*>::const_iterator itrendother1 = other.orderArray.end();
	for (; itrother1 != itrendother1; ++itr1, ++itrother1) {
		(*itr1) = (*itrother1);
	}


	this->userArray = other.userArray;
	this->orderArray = other.orderArray;
}

Manager::Manager(Manager && other) 
{
	setName(other.name);
	other.name = nullptr;
	this->userArray = other.userArray;
	this->orderArray = other.orderArray;
}

Manager::~Manager()
{
	vector<User*>::iterator itr1 = userArray.begin();
	vector<User*>::iterator itrEnd1 = userArray.end();
	for (; itr1 != itrEnd1; ++itr1)  // delete users
	{
		delete (*itr1);
	}

	vector<Order*>::iterator itr = orderArray.begin();
	vector<Order*>::iterator itrEnd = orderArray.end();
	for (; itr != itrEnd; ++itr)  // delete orders
	{
		delete (*itr);
	}

}
const string& Manager::getName() const
{
	return name;
}
//func that sets the name of the system
bool Manager::setName(const string& name)
{
	this->name = name;
	return true;
}
//func that adds buyer to the buyers array

void Manager::addUser(User* user)
{
	if (userArray.size() == userArray.capacity())
	{
		userArray.reserve(userArray.capacity() * 2);
	}
	userArray.push_back(user);
}

//func that adds order to the order array
void Manager::addOrder(Order* order)
{
	if (orderArray.size() == orderArray.capacity())
	{
		userArray.reserve(userArray.capacity() * 2);
	}
	orderArray.push_back(order);
}

unsigned int Manager::get_Logical_Number_Of_Users() const
{
	return userArray.size();
}

unsigned int Manager::get_Physical_Number_Of_Users() const
{
	return userArray.capacity();
}

unsigned int Manager::get_Logical_Number_Of_Orders() const
{
	return orderArray.size();
}

unsigned int Manager::get_Physical_Number_Of_Orders() const
{
	return orderArray.capacity();
}

vector<User *> Manager::getUserArray() const
{
	return this->userArray;
}


vector <Order*> Manager::getOrderArray() const
{
	return this->orderArray;
}

//func that returns the index of the seller in the array

User* Manager::findSellerPlace(const string& name) // return pointer to seller
{
	Seller* temp =nullptr;
	vector<User*>::iterator itr = userArray.begin();
	vector<User*>::iterator itrEnd = userArray.end();
	for (; itr != itrEnd; ++itr)  
	{
		if ((*itr)->getName().compare(name ) == 0 && dynamic_cast<Seller*>(*itr)!=NULL)
			return (*itr);
	}
	return nullptr;
}

//func that adds product to the seller
void Manager::addItemToSeller(Product* product, User* user)
{	
	Seller* temp;
	temp = dynamic_cast<Seller*>(user);
	if (temp) {
		temp->addProduct(product);
	}
	else {
		cout << "The Seller wassnt found";
	}
}

 //func that checks if the username is already in the sellers/buyers array (cannot be 2 users with the same username)                                   
bool Manager::checkName(const string& name)
{
	vector<User*>::iterator itr = userArray.begin();
	vector<User*>::iterator itrEnd = userArray.end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName().compare( name) == 0) {
			return false;
		}
	}
	return true;
}
	

// func that checks if the buyer exists and is really a buyer, if so returns a pointer to him
Buyer* Manager::checkIfBuyer(const string& name)
{
	Buyer* temp;
	vector<User*>::iterator itr = userArray.begin();
	vector<User*>::iterator itrEnd = userArray.end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName().compare(name) == 0 && dynamic_cast<Buyer*>(*itr) != NULL)
			return temp = dynamic_cast<Buyer*>(*itr);
	}
	return nullptr;
}

//func that checks if the orders exists, if so returns a pointer to it
Order* Manager::checkIfOrderExists(const string& name) 
{
	unsigned int i;
	for (i = 0; i < this->get_Logical_Number_Of_Orders(); i++)
	{
		if (this->orderArray[i]->getBuyer()->getName().compare( name) == 0)
		{
			return this->orderArray[i];
		}
	}
	return nullptr;
}
// func that searches the purchases of the buyer and returns a bool if found or not
bool Manager::findBuyerPurchases(const string& name)
{
	bool found = false;
	for (unsigned int i = 0; i < this->get_Logical_Number_Of_Orders(); i++)
	{
		if ((this->orderArray[i]->getBuyer()->getName().compare(name) == 0) && this->orderArray[i]->getStatus()==true)
		{
			cout << "Order #" << (i + 1) <<endl ;
			this->orderArray[i]->printOrder();
			cout << endl;
			found = true;
		}
	}
	return found;
}
//func that prints all buyers details

void Manager::showDetails(const type_info &t, const type_info &t2) const
{
	vector<User*>::const_iterator itr = userArray.begin();
	vector<User*>::const_iterator itrEnd = userArray.end();
	int i = 0;
	for (; itr != itrEnd; ++itr) {
		if (typeid(**itr) == t || typeid(**itr) == t2)
		{
			cout << typeid(**itr).name() + 6 << " number #" << i + 1 << " details: \n";
			cout << **itr;
			i++;
		}
	}
}

//func that prints the product details and who is the seller of the product
void Manager::showProductsDetails(const string& productName) const
{
	Seller* temp;
	bool isok = false;

	vector<User*>::const_iterator itr = userArray.begin();
	vector<User*>::const_iterator itrEnd = userArray.end();

	for (; itr != itrEnd; ++itr)
	{
		temp = dynamic_cast<Seller*>(*itr);
		if (temp)
		{
			vector<Product*> lala = temp->getAllProducts();
			vector<Product*>::const_iterator itr1 = lala.begin();
			vector<Product*>::const_iterator itrEnd1 = lala.end();
			for (; itr1 != itrEnd1; ++itr1)
			{
				if ((*itr1)->getName().compare(productName) == 0)
				{
					cout << "the product belongs to:\n" << temp->getName() <<endl << *(*itr1);
					isok = true;
				}
			}
		}
	}
	if (!isok)
	{
		cout << "There are no products in this name \n";
	}
}
//func that prints the products of the seller
void Manager::printSellerProduct(Seller* seller)
{

	vector<Product*> temp = seller->getAllProducts();
	vector<Product*>::iterator itr = temp.begin();
	vector<Product*>::iterator itrEnd = temp.end();
		int i = 0;
		for (; itr != itrEnd; ++itr)
		{
			cout << "Product #" << i + 1 << endl;
			cout << **itr;
			i++;
		}
}

void Manager::checkOperatorGadol()
{
	bool res;
	int buyer1, buyer2;
	Buyer* valid1 = nullptr;
	Buyer* valid2 = nullptr;
	cout << "Please choose the number of the first buyer:\n";
	this->showDetails(typeid(Buyer), typeid(Combined));
	for (int i = 0; i < 3; i++) {
		cout << "\nBuyer selection:\n";

		Helper::getInt("buyer number", &buyer1, 1, this->get_Logical_Number_Of_Users());
		valid1 = dynamic_cast<Buyer*>(this->getUserArray()[buyer1 - 1]);
		if (!valid1) {
			cout << "The person you chose is not a buyer in the system\nPlease try again\n";
		}
		else
		{
			break;
		}
	}
	cout << "Please choose the number of the second buyer: ";
	for (int i = 0; i < 3; i++) {
		cout << "\nBuyer selection:\n";

		Helper::getInt("buyer number", &buyer2, 1, this->get_Logical_Number_Of_Users());
		valid2 = dynamic_cast<Buyer*>(this->getUserArray()[buyer2 - 1]);
		if (!valid2) {
			cout << "The person you chose is not a buyer in the system\nPlease try again\n";
		}
		else
		{
			break;
		}
	}
	res = *valid1 > *valid2;
	if (res == true)
	{
		cout << "The buyer that has a bigger cart is:\n";
		cout << *valid1<<endl;
	}
	else
	{
		cout << "The buyer that has a bigger cart is:\n";
		cout << *valid2 << endl;
	}
}

void Manager::saveUsers(const string& filename)
{
	ofstream outFile(filename, ios::trunc);
	int size = userArray.size();
	outFile << size << endl;

	vector<User*>::iterator itr = userArray.begin();
	vector<User*>::iterator itrEnd = userArray.end();

	for (; itr != itrEnd; ++itr)
	{
		outFile << *(*itr);
	}

	outFile.close();
}


void Manager::loadUsers(const string& filename)
{
	ifstream inFile(filename);
	if (inFile.is_open())
	{
		int size;
		string type;
		inFile >> size;
		getline(inFile, type);
		userArray.clear();
		userArray.reserve(size);
		for (int i = 0; i < size; i++)
		{
			getline(inFile, type);
			if (type == "Buyer")
				userArray.push_back(new Buyer(inFile));
			else if (type == "Seller")
				userArray.push_back(new Seller(inFile));
			else
				userArray.push_back(new Combined(inFile));
		}
	}
	inFile.close();
}

