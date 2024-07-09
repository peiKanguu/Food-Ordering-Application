#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User {
private:
	string surname;
	string forename;
	string name;
	string id;
	string passWord;
public:
	User(string surname, string forename, string name, string id, string passWord) :
		surname(surname), forename(forename), name(name), id(id), passWord(passWord) {}

	string getID() { return id; }
	string getPassWord() { return passWord; }

	void displayAccount() {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "~~~~~~~        ID: " << id << endl;
		cout << "~~~~~~~  Password: " << passWord << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;
	}
};

#endif // USER_H
