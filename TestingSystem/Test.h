#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Test 

{
	//string _testId;	
	string _tTitle;
	string _file;
	string _catName;
public:
	Test(string tTitle = "<No test title>", string file = "Tests.txt", string catName = "No category name" ) :
		_tTitle(tTitle), _file(file), _catName(catName)
	{}
	void setData()
	{
		cout << "Enter test title: ";
		cin >> _tTitle;
		this->_tTitle = _tTitle;

		cout << "Enter category name, which includes this test: ";
		cin >> _catName;
		this->_catName = _catName;
	}
	string getTitle()
	{
		return _tTitle;
	}
	string getCatName()
	{
		return _catName;
	}
	string getFile()
	{
		return _file;
	}
	~Test();
};

