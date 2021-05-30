#include "menu.h"

Menu::Menu(Manager* manager)
{
	choice = 0;
	this->manager = manager;
}


void Menu::showOptions()
{
	cout << "please choose an option from the following:\n";
	cout << "1.Add buyer \n";
	cout << "2.Add seller \n";
	cout << "3.Add an item to seller \n";
	cout << "4.Add feedback to seller \n";
	cout << "5.Add product to the cartshop of buyer \n";
	cout << "6.Make an order \n";
	cout << "7.Make a payment \n";
	cout << "8.Show the buyer's details \n";
	cout << "9.Show the seller's details \n";
	cout << "10.Show products in a specific name \n";
	cout << "11.Add combined user(buyer and a seller) \n";
	cout << "12.Show the combined users details\n";
	cout << "13.Check operator > \n";
	cout << "14.EXIT \n";
}

bool Menu::setChoice(int choice)
{
	bool canContinue = true;
	switch (choice) {
	case 1:
		readUser(1);
		break;
	case 2:
		readUser(2);
		break;
	case 3:
		addItemToSeller();
		break;
	case 4:
		addFeedbackToSeller();
		break;
	case 5:
		addProductToCart();
		break;
	case 6:
		makeAnOrder();
		break;
	case 7:
		makePayment();
		break;
	case 8:
		this->manager->showDetails(typeid(Buyer), typeid(Combined));
		break;
	case 9:
		this->manager->showDetails(typeid(Seller), typeid(Combined));
		break;
	case 10:
		showProduct();
		break;
	case 11:
		readUser(3);
		break;
	case 12:
		this->manager->showDetails(typeid(Combined), typeid(Combined));
		break;
	case 13:
		this->manager->checkOperatorGadol();
		break;
	case 14:
		canContinue = false;
		this->manager->saveUsers("amazon.txt");
		break;
	default:
		break;
	}

	return canContinue;
}

//func that gets info of the address from the user
Address* Menu::readAddress()
{ // maybe combine all the chars to one temp
	
	bool isOk = false;
	string state;
	string city;
	string street;
	string zipcode;

	int num;

	do {
		isOk = Helper::getLineString("state", state, MIN_LETTERS, NAME_LENGTH + 1);
		if (!isOk) {
			cout << "Wrong state name, try again" << endl;
		}
	} while (isOk == false);

	isOk = false;
	do {
		isOk = Helper::getLineString("city", city, MIN_LETTERS, NAME_LENGTH + 1);
		if (!isOk) {
			cout << "Wrong city name, try again" << endl;
		}
	} while (isOk == false);

	isOk = false;
	do {
		isOk = Helper::getLineString("street", street, MIN_LETTERS, NAME_LENGTH + 1);
		if (!isOk) {
			cout << "Wrong street name, try again" << endl;
		}
	} while (isOk == false);

	isOk = false;
	do {
		isOk = Helper::getInt("house number", &num, ZERO, TEN_MILLION);
		if (!isOk) {
			cout << "Wrong house number, try again" << endl;
		}
	} while (isOk == false);

	cin.ignore(); // clean the buffer
	isOk = false;
	do {
		isOk = Helper::getLineString("zip code", zipcode, MIN_LETTERS, NAME_LENGTH);
		if (!isOk) {
			cout << "Wrong  zip code, try again" << endl;
		}
	} while (isOk == false);

	return new Address(state,city,street,zipcode,num);
}
//func that gets info of the buyer/seller from the user

bool Menu::readUser(int type)  // finalcheck: waste of place 
{
	bool isOk = false;
	string name;
	string password;

	User* user=nullptr;
	cin.ignore(); // clean the buffer

	do {
		Helper::getLineString("your name", name, MIN_LETTERS, NAME_LENGTH - 1);
		isOk = this->manager->checkName(name);// checks if the name exists  

		if (!isOk)    //doesnt exit until the user enters a valid name (if exists) 
		{
			cout << "The username is already taken, please choose another " << endl;
		}
	} while (isOk == false);


	isOk = false;
	do {
		isOk = Helper::getLineString("password", password, MIN_LETTERS, PASSWORD_LENGTH - 1);
		if (!isOk) {
			cout << "Wrong password, try again" << endl;
		}

	} while (isOk == false);

	
	Address* address = readAddress();

			if (type==1) {
				user = new Buyer(name,password, *address);
			}
			else if(type == 2) {
				user = new Seller(name, password, *address);
			}
			else if(type == 3) {
				user = new Combined(Buyer(name,password,*address) , Seller(name, password, *address));
			}
			*(this->manager)+= user;
	return true;
}

int Menu::getNumOfOptions()
{
	return NUM_OF_OPTIONS;
}

void Menu::addItemToSeller() {  
	string inputString;
	User* res = nullptr;

	for (int i = 0; i < 3 && res == nullptr; i++)
	{
		Helper::getString("seller name", inputString, MIN_LETTERS, NAME_LENGTH);
		res = manager->findSellerPlace(inputString);
		if (res == nullptr)
		{
			cout << "The seller doesnt exists in the system\n";
		}
	}
	if (res == nullptr)
	{
		cout << "You failed 3 times please try again.\n";
		return;
	}

	Seller* temp = dynamic_cast<Seller*>(res);
	Product * product = readProduct();
	product->setSeller(temp);
	this->manager->addItemToSeller(product, res);
}

bool Menu::addFeedbackToSeller() {
	bool isOk = false;
	Buyer* ptr;
	string inputString;

	cin.ignore();
	Helper::getLineString("your name", inputString, MIN_LETTERS, NAME_LENGTH);

	ptr = this->manager->checkIfBuyer(inputString);
	if (ptr == nullptr)
	{
		cout << "You are not a buyer in the system\n";
		return false;
	}
	isOk = this->manager->findBuyerPurchases(inputString);
	if (isOk == false)           //no purchases cant put feedback
	{
		cout << "You have no purchases\n";
		return false;
	}
	int choice, choice2;
	// need to update max possible choise

	Helper::getInt("order number that contains the product you want to give feedback on:", &choice, ZERO, TEN_MILLION);//check
	cout << "\nOrder #" << choice << endl;
	this->manager->getOrderArray()[choice - 1]->printOrder();
	Helper::getInt("\nserial number of the product you want to give feedback on:", &choice2, ZERO, TEN_MILLION);

	Product* product = this->manager->getOrderArray()[choice - 1]->getBuyerOrder()[choice2 - 1];
	Feedback* feedback = new Feedback;
	feedback->setBuyer(ptr);

	string review;
	cin.ignore();
	Helper::getLineString("your review", review, MIN_LETTERS, REVIEW_LENGTH);
	feedback->setReview(review);
	product->getSeller()->addFeedback(feedback);/////
	cout << "Youre feedback has been entered, Thank you\n";
	return true;
	
}

bool Menu::addProductToCart()
{
	bool isOk = false;
	Buyer* ptr;
	Seller* valid;
	string inputString;

	cin.ignore();
	Helper::getLineString("your name", inputString, MIN_LETTERS, NAME_LENGTH);

	ptr = this->manager->checkIfBuyer(inputString);
	if (ptr == nullptr)
	{
		cout << "You are not a buyer in the system\n";
		return false;
	}
	this->manager->showDetails(typeid(Seller), typeid(Combined));
	int num, num1;
	for (int i = 0; i < 3; i++) {
		cout << "Seller selection:\n";
		Helper::getLineString("seller's name", inputString, MIN_LETTERS, NAME_LENGTH);
		valid = dynamic_cast<Seller*>(this->manager->findSellerPlace(inputString));

		if (!valid) {
			cout << "The person you chose is not a seller in the system\nPlease try again\n";
		}
		else
			break;
	}


	this->manager->printSellerProduct(dynamic_cast<Seller*>(valid));
	cout << "Product selectiont:\n";

	Helper::getInt("product's serial number", &num1, 1, TEN_MILLION);
	Product* product = valid->getSpecificProduct(num1);

	if (product == nullptr)
	{
		cout << "there is no such product\n";
		return false;
	}
	ptr->getCart().addProduct(product);
	return true;
}

bool Menu::makeAnOrder()
{
	if (this->manager->get_Logical_Number_Of_Users() == 0) {
		cout << "There are no Buyers currently in the system.\n";
		return false;
	}
	bool isOk = false;
	int toContinue = 1;
	Buyer* ptr;
	string inputString;

	cin.ignore();
	Helper::getLineString("your name", inputString, MIN_LETTERS, NAME_LENGTH);

	ptr = this->manager->checkIfBuyer(inputString);
	if (ptr == nullptr)
	{
		cout << "You are not a buyer in the system\n";
		return false;
	}

	vector<Product *> products = ptr->getCart().getproductsArray();
	if (products.size() == 0) {
		cout << "Your chart is empty\n";
		return false;
	}

	//is buyer
	cout << "These are your products\n";
	ptr->getCart().showProducts(); // printing buyer products
	Order* order = new Order;
	order->setBuyer(ptr);
	int num = 0;

	while (toContinue)
	{
		cout << "Product selection:\n";
		Helper::getInt("product number you want to add to the order", &num, 1, ptr->getCart().get_Logical_Num_Of_Products_In_Cart());
		cout << endl;
		order->addProduct(ptr->getCart().getproductsArray()[num - 1]);
		if (ptr->getCart().get_Logical_Num_Of_Products_In_Cart() == order->get_Logical_Number_Of_Products()) //checking that there are products in the cart **********
		{
			this->manager->addOrder(order);
			return true;
		}
		cout << "Do you want to add another product to your order? \nfor yes prees 1\nfor no prees 0\n";
		Helper::getInt("your choise", &toContinue, ZERO, 1);
	}
	this->manager->addOrder(order);
	return true;
}

bool Menu::makePayment()
{

	if (this->manager->get_Logical_Number_Of_Users() == 0) {
		cout << "There are no Buyers currently in the system.\n";
		return false;
	}
	string inputString;
	Buyer* ptr;

	cin.ignore();
	Helper::getLineString("your name", inputString, MIN_LETTERS, NAME_LENGTH);
	ptr = this->manager->checkIfBuyer(inputString);
	if (ptr == nullptr)
	{
		cout << "You are not a buyer in the system\n";
		return false;
	}
	Order* order = this->manager->checkIfOrderExists(inputString);
	if (order == nullptr)
	{
		cout << "An order with this username doesn't exists";
		return false;
	}
	if (order->getStatus() == true)
	{
		cout << "The order already has been paid\n";
		return false;
	}
	order->printOrder();
	int isPaid;
	cout << "\nDo you want to pay for the order?\nFor yes press 1\nFor no press 0\n";
	Helper::getInt("your choise", &isPaid, ZERO, 1);

	if (isPaid == 0)
	{
		cout << "The order has not been paid\n";
		return false;
	}
	else
	{
		cout << "The order has been paid\n";
		order->setStatus(isPaid);
	}
	return true;
}

bool Menu::showProduct()
{
	string inputString;

	cin.ignore();
	Helper::getLineString("product name", inputString, MIN_LETTERS, NAME_LENGTH);
	this->manager->showProductsDetails(inputString);
	return true;
}
//func that gets information of the product that the seller wants to add
Product* Menu::readProduct()
{
	bool isOk = false;
	Product* product = new Product;

	string inputString;

	cin.ignore();

	do {
		Helper::getLineString("product name", inputString, MIN_LETTERS, NAME_LENGTH);

		isOk = product->setName(inputString);
		if (!isOk) {
			cout << "Wrong product name, try again" << endl;
		}
	} while (isOk == false);

	float price;
	cout << "Set price:\n";
	cin >> price;
	do {
		isOk = product->setPrice(price);
		if (!isOk) {
			cout << "The price must be positive \n";  // check only numbers
			cout << "Set price:\n";
			cin >> price;
		}
	} while (isOk == false);

	int category;
	cout << "Please choose the category of the product:\n";
	cout << "For Children insert 0:\nFor Electricity insert 1\nFor Office insert 2\nFor Clothing insert 3\n";
	Helper::getInt("your choise", &category, ZERO, 3);
	isOk = product->setCategory((Product::eCategoryType)category);

	return product;
}









