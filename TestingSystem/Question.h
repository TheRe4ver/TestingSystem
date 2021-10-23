#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Question	
{
	string _quest;
	string _file;
	string _testName;
public:
	Question(string quest = "<No question>", string file = "Questions.txt", string testName = "<No test name>") :
		_quest(quest), _file(file), _testName(testName)
	{}
	void setData()
	{
		cout << "Enter question: " << endl;
		cin >> _quest;
		this->_quest = _quest;
		cout << "Enter test name, which includes this question: " << endl;
		cin >> _testName;
		this->_testName = _testName;
	}
	string getQuest()
	{
		return _quest;
	}
	string getTestName()
	{
		return _testName;
	}
	string getFile()
	{
		return _file;
	}
	~Question();
};

