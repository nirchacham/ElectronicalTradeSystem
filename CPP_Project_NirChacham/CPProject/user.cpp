#include "user.h"

//--------------------------------------------------------------------------------//
User::User(const string& name, const string& password, const Address& address) : address(address)
{
	this->name = name;
	this->password = password;	
}

User::User(ifstream & inFile) : address(inFile)
{
	getline(inFile, name);
	getline(inFile, password);

}

//--------------------------------------------------------------------------------//
User::User(const User& other) : address(other.address)
{
	setName(other.name);
	setPassword(other.password);
}

//--------------------------------------------------------------------------------//
User::User(User&& other) : address(other.address)
{
	setName(other.name);
	other.name = nullptr;
	setPassword(other.password);
	other.password = nullptr;
}

//--------------------------------------------------------------------------------//
User::~User()
{

}


const string& User::getName() const
{
	return name;
}

const string& User::getPassword() const
{
	return password;
}

Address * User::getAddress() 
{
	return &(this->address);
}

//func that sets the name
bool User::setName(const string& name)
{
	this->name = name;
	return true;

}
//func that sets the password
bool User::setPassword(const string& password)
{
	this->password = password;
	return true;
}
//func that sets the address
bool User::setAddress(const Address& address)
{
	this->address.setState(address.getState());
	this->address.setCity(address.getCity());
	this->address.setStreet(address.getStreet());
	this->address.setHouseNumber(address.getHouseNumber());
	this->address.setZipCode(address.getZipCode());
	return true;
}

