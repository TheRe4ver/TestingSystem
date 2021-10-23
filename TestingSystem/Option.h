#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Option
{
	string _option;
	string _isCorrect;
	string _file;
	string _questName;
public:
	Option(string option = "<No option>", string isCorrect = "Unknown", string file = "Options.txt", string questName = "<No question name>") :
		_option(option), _isCorrect(isCorrect), _file(file), _questName(questName)
	{}
	void setQuestName(string quest)
	{/*
		cout << "Enter question name, which contains this variant: ";
		cin >> _questName;*/
		this->_questName = quest;
	}
	void setData()
	{
		cout << "Enter variant(option) for question: ";
		cin >> _option;
		this->_option = _option;

		cout << "Is that variant right or no(y, n): ";
		cin >> _isCorrect;
		this->_isCorrect = _isCorrect;



	}
	string getFile()
	{
		return _file;
	}
	string getOption()
	{
		return _option;
	}
	string getIsCor()
	{
		return _isCorrect;
	}
	string getQuestName()
	{
		return _questName;
	}

	~Option();
};

