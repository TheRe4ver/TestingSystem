#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


class User 	
{
	string _role;
	string _login;
	string _pw;
	string _addr;
	string _phone;
	string _file;
public:
	User(string role = "Unknown", string login = "<No login>", string pw = "0", string addr = "<No address>", string phone = "0", string file = "Users.txt") :
		_role(role), _login(login), _pw(pw), _addr(addr), _phone(phone), _file(file)
	{}
	void setData();
	void setLogin()
	{
		cout << "Enter login: ";
		cin >> _login;
		this->_login = _login;
	}
	void setPw()
	{
		cout << "Enter password: ";
		cin >> _pw;
		this->_pw = _pw;
	}
	
	string getLogin()
	{
		return _login;
	}
	string getPw()
	{
		return _pw;
	}
	string getRole()
	{
		return _role;
	}
	string getAddr()
	{
		return _addr;
	}
	string getPhone()
	{
		return _phone;
	}
	string getFile()
	{
		return _file;
	}
	~User();
};

