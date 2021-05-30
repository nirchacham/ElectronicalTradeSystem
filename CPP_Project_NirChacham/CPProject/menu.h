#ifndef __MENU_H
#define __MENU_H
#include "manager.h"
#include "helper.h"


class Menu
{
private:
	int choice;
	Manager* manager;
public:
	Menu(Manager* manager);

	bool setChoice(int choice);
	bool readUser(int type);
	int getNumOfOptions();
	Address* readAddress();

	Product* readProduct();
	void showOptions();
	void addItemToSeller();
	bool addFeedbackToSeller();
	bool addProductToCart();
	bool makeAnOrder();
	bool makePayment();
	bool showProduct();


};

#endif // __MENU_H