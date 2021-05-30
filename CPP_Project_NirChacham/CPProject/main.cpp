#include "menu.h"
#include "helper.h"

/*
Nir Chacham, 313298648
Tuesday, Keren Kalif
*/


int main() {
	string name;

	Helper::getLineString("system name", name, 3, NAME_LENGTH);

	Manager* manager = new Manager(name);
	manager->loadUsers("amazon.txt");
	bool isOk = true;
	Menu* menu = new Menu(manager);
	
	int choice;


	while (isOk)
	{
		menu->showOptions();
		cout << "*-------------------------------------------------------------------------*\n";
		Helper::getInt("your choise", &choice, 1, menu->getNumOfOptions());
		isOk = menu->setChoice(choice);
	}

}

