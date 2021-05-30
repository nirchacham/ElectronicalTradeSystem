#ifndef _ADDRESS_H
#define _ADDRESS_H
#include "helper.h"

class Address
{
private:

	string state;
	string city;
	string street;
	unsigned short int houseNumber;
	string zipcode;

public: 
	Address() = default;
	Address(const string& state, const string& city, const string& street, const string& zipcode,const unsigned short int houseNumber);
	Address(ifstream& inFile);

	friend ostream& operator<<(ostream& os, const Address& address)
	{
		if (typeid(os) == typeid(ofstream)) {
			os << address.state << endl << address.city << endl << address.street << endl << address.houseNumber <<endl<<address.zipcode<<endl;
		}
		else {
			os << "State: " << address.getState() << endl << "City: " << address.getCity() << endl <<
				"Street: " << address.getStreet() << endl << "House number: " << address.getHouseNumber() << endl <<
				"Zipcode: " << address.getZipCode() << endl
				<< "*--------------------------------------------------------------------------*\n";
		}
		return os;
	}
	friend istream& operator>>(istream& in, Address& address)
	{
		char delimiter;
		in >> delimiter >> address.state >> delimiter >> address.city >> delimiter >> address.street>>delimiter>>
			address.houseNumber>>delimiter>>address.zipcode;
		return in;
	}

	
	const string& getState()         const;
	const string& getCity()          const;
	const string& getStreet()        const;
	unsigned short int getHouseNumber()        const;
	const string& getZipCode()       const;
	const void printAddress()         const;

	bool setState(const string& state);
	bool setCity(const string& city);
	bool setStreet(const string& street);
	bool setHouseNumber(const unsigned short int houseNumber);
	bool setZipCode(const string& zipcode);
};


#endif // _ADDRESS_H
