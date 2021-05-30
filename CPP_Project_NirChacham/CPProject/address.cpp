#include "address.h"

Address::Address(const string& state, const string& city, const string& street,const string& zipcode, const unsigned short int houseNumber)
{
	setState(state);
	setCity(city);
	setStreet(street);
	setZipCode(zipcode);
	setHouseNumber(houseNumber);
}

Address::Address(ifstream & inFile)
{
	string erase;
	string numberString;

	getline(inFile, state);
	getline(inFile, city);
	getline(inFile, street);
	getline(inFile, numberString);
	houseNumber = std::stoi(numberString, nullptr);
	getline(inFile, zipcode);
}



const string& Address::getState() const
{
	return state;
}


const string& Address::getCity() const
{
	return city;
}

const string& Address::getStreet() const
{
	return street;
}

 unsigned short int Address::getHouseNumber() const
{
	return houseNumber;
}

 const string& Address::getZipCode() const
{
	return zipcode;
}

 //func that sets the state
bool Address::setState(const string& state)
{
	this->state = state;
	return true;
}

//func that sets the city
bool Address::setCity(const string& city)
{
	this->city = city;
	return true;
}

//func that sets the street
bool Address::setStreet(const string& street)
{
	this->street = street;
	return true;

}

//func that sets the house number
bool Address::setHouseNumber(const unsigned short int houseNumber)
{
	if (houseNumber< 0)
	{
		return false;
	}

	this->houseNumber = houseNumber;
	return true;

}

//func that sets the zipcode
bool Address::setZipCode(const string& zipcode)
{
	this->zipcode = zipcode;
	return true;
}
