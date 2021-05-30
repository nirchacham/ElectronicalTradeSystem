#ifndef _USER_H
#define _USER_H

#include "helper.h"
#include "address.h"

class User
{

protected:
	string name;
	string password;
	Address address;
	
	User() = default;
	User(const string& name,const string& password, const Address& address);
	User(ifstream& inFile);
	User(const User& other);
	User(User&& other);
	virtual ~User();


public:

	const string& getName()             const;
	const string& getPassword()         const;
	Address * getAddress();
	bool setName(const string& name);
	bool setPassword(const string& password);
	bool setAddress(const Address& address);
	
	friend ostream& operator<<(ostream& os, const User& user)
	{
		if (typeid(os) == typeid(ofstream)) {
			
			os << typeid(user).name() + 6 << endl << user.address << user.name << endl << user.password
				<< endl;
		}
		else {
			os << "Name: " << user.getName() << endl << "Address:\n";
			os << user.address;
			os << "*--------------------------------------------------------------------------*\n";
		}
		return os;
	}
	friend istream& operator>>(istream& in, User& user)
	{
		char delimiter;
		in >> delimiter >> user.address >> delimiter >> user.name >> delimiter >> user.password;
		return in;
	}

	friend class Manager;
};

#endif // _USER_H

