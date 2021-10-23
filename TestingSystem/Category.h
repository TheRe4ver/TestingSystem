#pragma once
#include <string>
#include <fstream>

#include <iostream>
using namespace std;

class Category

{

	string _cTitle;
	string _file;
public:
	Category(string cTitle = "<No category title>", string file = "Categories.txt") :
		_cTitle(cTitle), _file(file)
	{}
	void setTitle()
	{
		cout << "Enter category title: " << endl;
		cin >> _cTitle;
		this->_cTitle = _cTitle;
	}
	string getTitle()
	{
		return _cTitle;
	}
	string getFile()
	{
		return _file;
	}

	~Category();
};

