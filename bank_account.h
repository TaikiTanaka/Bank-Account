#pragma once
#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
const int MAX = 30;


class BankAccount{
private:
	string account_number;
	string first_name;
	string last_name;
	double balance;
public:
	BankAccount();
	BankAccount(string actN, string fname, string lname,double bal);
	const string toString() const;
	void set_account_number(string actN);
	void set_lname(string lname);
	string get_fname() const;
	string get_lname()const;
	string get_account_number()const;
	string get_full_name()const;
	double get_balance()const;
	void deposit(double money);
	void withdraw(double money);
	void print (ofstream &fout);
	void print ();
	static void getinstance(BankAccount & BA);
	static void getinstance(BankAccount & BA, istream&fin);
};
#endif