#include "User.h"
#include "Category.h"
#include "Test.h"
#include "Question.h"
#include "Option.h"
#include "UserAnswer.h"
#include <vector>

bool FileExists(string File)
{
	ifstream ifs(File);
	if (ifs.is_open())
	{
		return true;
	}
	else
	{
		return false;
	}
}

string encryptDecrypt(string toEncrypt)
{
	char key = 'K'; //Any char will work
	string output = toEncrypt;

	for (int i = 0; i < toEncrypt.size(); i++)
	{
		output[i] = toEncrypt[i] ^ key;
	}
	return output;
}

bool FileLogin(string search)
{
	bool isFound = 0;
	ifstream in("Users.txt");
	if (in.is_open())
	{
		while (!in.eof())
		{
			string temp = "";
			getline(in, temp);
			for (int i = 0; i < encryptDecrypt(search).size(); i++)
			{
				if (temp[i] == encryptDecrypt(search)[i])
				{
					isFound = 1;
				}
				else
				{
					isFound = 0;
					break;
				}
			}
		}
		if (in.eof() && (!isFound))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}



void main()
{
	cout << "Hello!" << endl;
	vector<User> users;
	vector<Question> quests;
	vector<Category> cats;
	vector<Option> options;
	vector<Test> tests;
	if (FileExists("Users.txt") == false)
	{
		cout << "Login in system(first login must be made by Administrator): " << endl;
		User admin;
		admin.setLogin();
		admin.setPw();
		ofstream out("Users.txt", ofstream::binary);
		if (out.is_open())
		{
			out << encryptDecrypt(admin.getLogin()) << endl;
			out << encryptDecrypt(admin.getPw()) << endl;


			out.close();
		}

		int choice;
		cout << "That is the first login, so some system functions will not be available." << endl;
		cout << "1 - create  user" << endl;
		cout << "2 - add category" << endl;
		cout << "3 - add test" << endl;
		cout << "4 - add question and variants for it" << endl;
		cout << "5 - change password" << endl;
		cout << "6 - relogin" << endl;
		cin >> choice;
		while (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7 || choice == 8)
		{
			switch (choice)
			{
				case 1:
				{
					
					int uAmount;
					cout << "Input quantity of users, that you want create: ";
					cin >> uAmount;
					users.resize(uAmount);
					ofstream out(users[0].getFile(), ios_base::app); 
					for (int i = 0; i < uAmount; i++)
					{
						users[i].setData();
					}
					if (out.is_open())
					{
						for (int i = 0; i < uAmount; i++)
						{
							out << encryptDecrypt(users[i].getLogin()) << endl;
							out << encryptDecrypt(users[i].getPw()) << endl;
							out << users[i].getAddr() << endl;
							out << users[i].getPhone() << endl;
						}
						out.close();
					}	
					break;
				}
				case 2:
				{
					int cAmount;
					cout << "Input quantity of categories, that you want create: ";
					cin >> cAmount;
					cats.resize(cAmount);
					ofstream out(cats[0].getFile(), ofstream::binary);
					for (int i = 0; i < cAmount; i++)
					{
						cats[i].setTitle();
					}
					if (out.is_open())
					{
						for (int i = 0; i < cAmount; i++)
						{
							out << cats[i].getTitle() << endl;
						}
						out.close();
					}
					break;
				}
				case 3:
				{
					int tAmount;
					cout << "Input quantity of tests, that you want create: ";
					cin >> tAmount;
					tests.resize(tAmount);
					ofstream out(tests[0].getFile(), ofstream::binary);
					for (int i = 0; i < tAmount; i++)
					{
						tests[i].setData();
					}
					if (out.is_open())
					{
						for (int i = 0; i < tAmount; i++)
						{
							out << tests[i].getTitle() << endl;
							out << tests[i].getCatName() << endl;
						}
						out.close();
					}
					break;
				}
				case 4:
				{
					int qAmount;
					cout << "Input quantity of questions, that you want create: ";
					cin >> qAmount;
					
					options.resize(qAmount * 3);



					for (int i = 0; i < qAmount; i++)
					{
						quests[i].setData();
						for (int j = 0; j < qAmount * 3; j++)
						{							
							options[j].setQuestName(quests[i].getQuest());
							
						}
						options[i].setData();
						options[i].setData();
						options[i].setData();
					}

					ofstream outO(options[0].getFile(), ofstream::binary);
					ofstream outQ(quests[0].getFile(), ofstream::binary);
				
					if (outQ.is_open() && outO.is_open())
					{
						for (int i = 0; i < qAmount; i++)
						{
							outQ << quests[i].getQuest() << endl;
							outQ << quests[i].getTestName() << endl;
						}
						for (int i = 0; i < qAmount * 3; i++)
						{
							outO << options[i].getOption() << endl;
							outO << options[i].getIsCor() << endl;
							outO << options[i].getQuestName() << endl;
						}
						outQ.close();
						outO.close();
					}
					break;
				}
				
				case 5:
				{
			
					cout << "Enter new info: " << endl << endl;
					admin.setLogin();
					admin.setPw();
					if (out.is_open())
					{
						out << encryptDecrypt(admin.getLogin()) << endl;
						out << encryptDecrypt(admin.getPw()) << endl;
						out.close();
					}
					break;
				}
				case 6:
				{
					// relog
				}

			}
			
			cout << "If you want to continue choose some digit from the menu, if no, press any other symbol: ";
			cin >> choice;
		}

		// только для первого входа админа
	}
	else
	{
		int dig;
		cout << "1 - login" << endl;
		cout << "2 - register" << endl;
		cin >> dig;
		while (dig == 1 || dig == 2)
		{
			switch (dig)
			{
				case 1:
				{
					// log
					string login, pw;
					cout << "Enter login: ";
					cin >> login;				
					cout << "Enter password: ";
					cin >> pw;

					while (true)
					{
						// не рационально сделано, желательно пофиксить
						//

						if (FileLogin(encryptDecrypt(login)) == true && FileLogin(encryptDecrypt(pw)) == true)
						{
							cout << "d";
							break;
							// успешный вход

						}
						else
						{
							int ch;
							cout << "Incorrect data" << endl;
							cout << "1 - try again" << endl;
							cout << "any other symbol - register" << endl;
							cin >> ch;
							if (ch == 1)
							{
								cout << "Enter login: ";
								cin >> login;
								cout << "Enter password: ";
								cin >> pw;
							}
							//четонетак
							else
							{
								User newUser1;
								newUser1.setData();
								users.push_back(newUser1);

								ofstream out(newUser1.getFile(), ios_base::app);
								if (out.is_open())
								{
									out << encryptDecrypt(newUser1.getLogin()) << endl;
									out << encryptDecrypt(newUser1.getPw()) << endl;
									out << newUser1.getAddr() << endl;
									out << newUser1.getPhone() << endl;
									out.close();
								}
								break;
							}
						}
					}
					break;
				}
				case 2:
				{
					User newUser;
					newUser.setData();
					users.push_back(newUser);

					ofstream out(newUser.getFile(), ios_base::app);
					if (out.is_open())
					{
						out << encryptDecrypt(newUser.getLogin()) << endl;
						out << encryptDecrypt(newUser.getPw()) << endl;
						out << newUser.getAddr() << endl;
						out << newUser.getPhone() << endl;
						out.close();
					}
					break;
				}
			}
				cout << "If you want to continue choose some digit from the menu, if no, press any other symbol: ";
				cin >> dig;
		}
		
	}
	

	system("pause");
}

