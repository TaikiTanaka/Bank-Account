/*
ID Block:
Author: Taiki Tanaka
Date: 2/4/2015
Project: Assignment 2
Compiler: Visual Studio 2012
Operating System: Windows 7
*/

#include "bank_account.h"


	//default constructor
	BankAccount::BankAccount()
	{
		balance = 0;
		first_name = "First name is not set";
		last_name = "Last name is not set";
		account_number = "Account number is not set";
	}
	//Explicit constructor
	BankAccount::BankAccount(string actN, string lname, string fname, double bal)
	{
		account_number = actN;
		first_name = fname;
		last_name = lname;

		while(bal < 0)//Checks for negative balance
		{
			cout << "That is an invalid balance value, please enter a new one: $";
			cin >> bal;
		}
		balance = bal;
	}
	//Creates a string of the full name, account number, and balance of customer

	const string BankAccount:: toString() const
	{
		ostringstream os;
		os << left<<fixed << showpoint << setprecision(2);
		os << "Name: " << first_name << ' '<< last_name << endl
			<< "Account number: " << account_number << endl
			<<"Balance: $"<< balance<<endl;
		os << "========================================"<< endl;
		return os.str();
	}

	//Mutators
	void BankAccount::set_account_number(string actN)
	{
		account_number = actN;
	}
	void BankAccount::set_lname(string lname)
	{
		last_name = lname;
	}

	//Get functions
	string BankAccount::get_fname() const
	{
		return first_name;
	}
	string BankAccount::get_lname() const
	{
		return last_name;
	}
	string BankAccount::get_account_number() const
	{
		return account_number;
	}
	string BankAccount::get_full_name() const
	{
		return first_name + ' ' + last_name;
	}
	double BankAccount::get_balance() const
	{
		return balance;
	}

//Deposits valid amount of money into bank account
	void BankAccount::deposit(double money)
	{
		while(money<0)
		{
		cout << "Invalid deposit amount, no change to the balance has been made";
		return;
		}
		balance +=money;
		cout <<"Successfully deposited $" <<money << endl << endl;
	}

//Withdraws valid amount of money into bank account
	void BankAccount::withdraw(double money)
	{
		if (money < 0)
		{
		cout << "Cannot withdraw a negative amount, no change has been made";
		}
		else if (money > balance)
		{
		cout << "Cannot withdraw more than is currently in the balance, no change has been made";
		}
		else
		{
			balance-=money;
		cout <<"Successfully withdrew $" <<money << endl << endl;
		}
	}

//Prints data onto the console and an output file
	void BankAccount::print (ofstream &fout)
	{
		fout << "Name: "<< first_name << ' ' << last_name << endl << "Account number: " << account_number << endl << "Current Balance: $" << balance << endl;
	}

	void BankAccount::print ()
	{
		cout << "Name: "<< first_name << ' ' << last_name << endl << "Account number: " << account_number << endl << "Current Balance: $" << balance << endl<<endl<<endl;
	}

//Takes a blank BA and prompts the user for the information
 void BankAccount:: getinstance(BankAccount & BA)
	{
		string fname,lname,acN;
		double bal;
		cout << "Please enter the first name: ";
		cin >> fname;
		cout << "Please enter the last name: ";
		cin >>lname;
		cout << "Please enter the account number: ";
		cin >> acN;
		cout << "Please enter the balance: ";
		cin >>bal;
		BA = BankAccount(acN, fname, lname,bal);
	}

void BankAccount:: getinstance(BankAccount & BA, istream&fin)
{
	string fname,lname,acN;
	double bal;

		fin >> acN;
		fin >> lname;
		fin >> fname;
		fin >> bal;
		BA = BankAccount(acN,lname,fname,bal);
}
















