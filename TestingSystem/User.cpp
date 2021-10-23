#include "User.h"

void User::setData()
{
	cout << "Enter login: ";
	cin >> _login;
	this->_login = _login;

	cout << "Enter password: ";
	cin >> _pw;
	this->_pw = _pw;

	cout << "Enter your address: ";
	cin >> _addr;
	this->_addr = _addr;

	cout << "Enter phone number: ";
	cin >> _phone;
	this->_phone = _phone;
}





User::~User()
{
}
