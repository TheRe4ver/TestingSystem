#pragma once
#include <string>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

class UserAnswer
	
{
	//string _answerId;
	string _file;
public:
	UserAnswer(string file = "UserAnswers.txt") :
		_file(file)
	{}
	~UserAnswer();
};

